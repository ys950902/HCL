#include "coordinator.h"
#include <string.h>

bool coordinator_t::start(uint32_t io_threads, const sockaddr_t& addr)
{
    RET_ON_FALSE(asio_.start(io_threads));
    RET_ON_FALSE(srv_.listen(addr));
    RET_ON_FALSE(asio_.arm_monitor(srv_));

    return true;
}

bool coordinator_t::stop()
{
    asio_.stop();
    asio_.remove(srv_);
    srv_.close_socket();

    return true;
}

void coordinator_t::on_error(socket_base_t& s)
{
    HLCP_ERR("({}){}. {}", errno, strerror(errno), s);

    if (s.fd == srv_.fd)
    {
        return;
    }

    on_disconnect(s);
}

#define hlcp2sock(c) (static_cast<xsocket_t&>((socket_io_t&)(c)))

void coordinator_t::close_connection(hlcp_t& c)
{
    c.send_ack();

    xsocket_t& xs = hlcp2sock(c);

    xs.marked = true;
    xs.arm_monitor();
}

void coordinator_t::drop_connection(hlcp_t& c)
{
    xsocket_t& xs = hlcp2sock(c);
    xs.marked = true;

    on_disconnect(xs);
}

void coordinator_t::on_disconnect(socket_base_t& s)
{
    HLCP_LOG("{}", s);

    xsocket_t& xs = static_cast<xsocket_t&>(s);

    hlcp_t& connection = (hlcp_t&)xs;

    if (!xs.marked)
    {
        HLCP_ERR("peer disconnected", s);
    }

    asio_.remove(xs);
    xs.close();

    delete &xs;

    destroy_connection(connection);
}

void coordinator_t::on_accept(socket_base_t& s, int new_socket_fd)
{
    HLCP_LOG("accepted({})-->{}", s.fd, new_socket_fd);

    xsocket_t& xs = *new xsocket_t(new_socket_fd, *this, &asio_);

    hlcp_t& conn = create_connection(xs);

    xs = conn;

    HLCP_LOG("{}", xs.str());

    conn.notify_->on_connect(conn);
}