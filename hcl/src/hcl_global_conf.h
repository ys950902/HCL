#pragma once

#include <hl_gcfg/hlgcfg_item.hpp>

using GlobalConfUint64 = hl_gcfg::GcfgItemUint64;
using GlobalConfInt64  = hl_gcfg::GcfgItemInt64;
using GlobalConfSize   = hl_gcfg::GcfgItemSize;
using GlobalConfBool   = hl_gcfg::GcfgItemBool;
using GlobalConfFloat  = hl_gcfg::GcfgItemFloat;
using GlobalConfString = hl_gcfg::GcfgItemString;

extern GlobalConfBool   GCFG_HCL_HNIC_IPV6;
extern GlobalConfBool   GCFG_HCL_HNIC_LTU;
extern GlobalConfBool   GCFG_USE_CPU_AFFINITY;
extern GlobalConfSize   GCFG_HCL_IMB_SIZE;
extern GlobalConfSize   GCFG_FW_IMB_SIZE;
extern GlobalConfUint64 GCFG_HCL_MIN_IMB_SIZE_FACTOR;
extern GlobalConfUint64 GCFG_HCL_SCALEOUT_BUFFER_FACTOR;
extern GlobalConfSize   GCFG_HCL_SLICE_SIZE;
extern GlobalConfSize   GCFG_HCL_GDR_SLICE_SIZE;
extern GlobalConfUint64 GCFG_HCL_DEBUG_STATS_LEVEL;
extern GlobalConfString GCFG_HCL_DEBUG_STATS_FILE;
extern GlobalConfString GCFG_HABANA_PROFILE;
extern GlobalConfBool   GCFG_HCL_GET_IMB_SIZE_BC;
extern GlobalConfInt64  GCFG_BURST_SIZE;
extern GlobalConfInt64  GCFG_REQUESTER_PRIORITY;
extern GlobalConfInt64  GCFG_RESPONDER_PRIORITY;
extern GlobalConfInt64  GCFG_CONGESTION_WINDOW;
extern GlobalConfUint64 GCFG_CONGESTION_CONTROL_ENABLE;
extern GlobalConfString GCFG_HCL_MAC_INFO_FILE;
extern GlobalConfString GCFG_HCL_GAUDINET_CONFIG_FILE;
extern GlobalConfBool   GCFG_HCL_ALIVE_ON_FAILURE;
extern GlobalConfUint64 GCFG_BOX_TYPE_ID;
extern GlobalConfString GCFG_BOX_TYPE;
extern GlobalConfBool   GCFG_WEAK_ORDER;
extern GlobalConfBool   GCFG_ENABLE_DEPENDENCY_CHECKER;
extern GlobalConfBool   GCFG_NOTIFY_ON_CCB_HALF_FULL_FOR_DBM;
extern GlobalConfUint64 GCFG_LOOPBACK_COMMUNICATOR_SIZE;
extern GlobalConfUint64 GCFG_LOOPBACK_SCALEUP_GROUP_SIZE;
extern GlobalConfString GCFG_LOOPBACK_DISABLED_NICS;
extern GlobalConfUint64 GCFG_HCL_LONGTERM_GPSO_COUNT;

extern GlobalConfBool   GCFG_HCCL_OVER_OFI;
extern GlobalConfBool   GCFG_HCCL_GAUDI_DIRECT;
extern GlobalConfBool   GCFG_HCL_FABRIC_FLUSH;
extern GlobalConfBool   GCFG_HCCL_ASYNC_EXCHANGE;
extern GlobalConfString GCFG_HCCL_SOCKET_IFNAME;
extern GlobalConfString GCFG_HCCL_COMM_ID;
extern GlobalConfInt64  GCFG_HCCL_TRIALS;

extern GlobalConfSize GCFG_HCL_COMPLEX_BCAST_MIN_SIZE;
extern GlobalConfBool GCFG_HCL_USE_SINGLE_PEER_BROADCAST;
extern GlobalConfBool GCFG_HCL_IS_SINGLE_PEER_BROADCAST_ALLOWED;

extern GlobalConfBool  GCFG_HCL_LOG_CONTEXT;
extern GlobalConfInt64 GCFG_HOST_SCHEDULER_SLEEP_THRESHOLD;
extern GlobalConfInt64 GCFG_HOST_SCHEDULER_SLEEP_DURATION;
extern GlobalConfInt64 GCFG_HOST_SCHEDULER_THREADS;
extern GlobalConfInt64 GCFG_HOST_SCHEDULER_STREAM_DEPTH_PROC;
extern GlobalConfInt64 GCFG_OFI_CQ_BURST_PROC;

extern GlobalConfSize GCFG_MTU_SIZE;
extern GlobalConfSize GCFG_HCL_SRAM_SIZE_RESERVED_FOR_HCL;
extern GlobalConfBool GCFG_HCL_FAIL_ON_CHECK_SIGNALS;
extern GlobalConfBool GCFG_HCL_ALLOW_GRAPH_CACHING;

extern GlobalConfString GCFG_HCL_RDMA_DEFAULT_PATH;
extern GlobalConfBool   GCFG_HCL_IBV_GID_SYSFS;
extern GlobalConfBool   GCFG_HCL_USE_NIC_COMPRESSION;

extern GlobalConfBool GCFG_HCL_NULL_SUBMIT;

extern GlobalConfBool   GCFG_HCL_COLLECTIVE_LOG;
extern GlobalConfInt64  GCFG_OP_DRIFT_THRESHOLD_MS;
extern GlobalConfUint64 GCFG_SCALE_OUT_PORTS_MASK;
extern GlobalConfUint64 GCFG_LOGICAL_SCALE_OUT_PORTS_MASK;
extern GlobalConfString GCFG_HCL_PORT_MAPPING_CONFIG;

extern GlobalConfUint64 GCFG_HCL_MAX_RANKS;
extern GlobalConfUint64 GCFG_HOST_SCHEDULER_OFI_DELAY_MSG_THRESHOLD;
extern GlobalConfUint64 GCFG_HOST_SCHEDULER_OFI_DELAY_ACK_THRESHOLD;
extern GlobalConfUint64 GCFG_HOST_SCHEDULER_OFI_DELAY_ACK_THRESHOLD_LOG_INTERVAL;
extern GlobalConfUint64 GCFG_HCL_SUBMIT_THRESHOLD;

extern GlobalConfUint64 GCFG_MAX_QP_PER_EXTERNAL_NIC;
extern GlobalConfUint64 GCFG_HCL_GNIC_SCALE_OUT_QP_SETS;
extern GlobalConfUint64 GCFG_HCL_HNIC_SCALE_OUT_QP_SETS;
extern GlobalConfUint64 GCFG_HCL_GNIC_QP_SETS_COMM_SIZE_THRESHOLD;
extern GlobalConfUint64 GCFG_HCL_HNIC_QP_SETS_COMM_SIZE_THRESHOLD;
extern GlobalConfSize   GCFG_HCL_HNIC_QP_SPRAY_THRESHOLD;
extern GlobalConfBool   GCFG_HCL_ENABLE_G3_SR_AGG;
extern GlobalConfBool   GCFG_ENABLE_HNIC_MICRO_STREAMS;
extern GlobalConfBool   GCFG_HCL_REDUCE_NON_PEER_QPS;
extern GlobalConfBool   GCFG_HCCL_GET_MACS_FROM_DRIVER;
extern GlobalConfBool   GCFG_HCL_ENABLE_HLCP;
extern GlobalConfUint64 GCFG_HCL_HLCP_CLIENT_IO_THREADS;
extern GlobalConfUint64 GCFG_HCL_HLCP_SERVER_IO_THREADS;
extern GlobalConfUint64 GCFG_HCL_HLCP_SERVER_SEND_THREAD_RANKS;
extern GlobalConfUint64 GCFG_HCL_HLCP_OPS_TIMEOUT;
extern GlobalConfBool   GCFG_HCL_SINGLE_QP_PER_SET;
extern GlobalConfBool   GCFG_HCL_PROFILER_DEBUG_MODE;
extern GlobalConfBool   GCFG_HCL_GEN_UNIQUE_SERVER_ID;
