#include "infra/scal/gaudi2/cyclic_buffer_manager.h"
#include <cmath>

hcl::Gaudi2CyclicBufferManager::Gaudi2CyclicBufferManager(ScalStreamBase*       scalStream,
                                                          ScalJsonNames&        scalNames,
                                                          CompletionGroup&      cg,
                                                          uint64_t              hostAddress,
                                                          scal_stream_info_t&   streamInfo,
                                                          uint64_t              bufferSize,
                                                          std::string&          streamName,
                                                          scal_stream_handle_t& streamHandle,
                                                          Gen2ArchScalWrapper&  scalWrapper,
                                                          unsigned              schedIdx,
                                                          HclCommandsGen2Arch&  commands)
: CyclicBufferManager(scalStream,
                      scalNames,
                      cg,
                      hostAddress,
                      streamInfo,
                      bufferSize,
                      streamName,
                      streamHandle,
                      scalWrapper,
                      schedIdx,
                      commands)
{
}

uint64_t hcl::Gaudi2CyclicBufferManager::getPi()
{
    static const uint64_t shift = std::log2(m_bufferSize);
    static const uint64_t mask  = ((1 << shift) - 1);
    return m_pi & mask;
}

void hcl::Gaudi2CyclicBufferManager::incPi(uint32_t size)
{
    m_pi += size;
    m_hostPi             = getPi();
    m_sizeSinceAlignment = 0;
}