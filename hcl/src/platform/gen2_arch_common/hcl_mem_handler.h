#pragma once

#include <cstddef>                                            // for NULL
#include <cstdint>                                            // for set
#include "infra/scal/gen2_arch_common/scal_names.h"           // for SchedulersIndex
#include "platform/gen2_arch_common/hcl_address_generator.h"  // for HclAddressGenerator
#include "platform/gen2_arch_common/types.h"                  // for GEN2ARCH_HLS_BOX_SIZE
#include "platform/gen2_arch_common/signals/types.h"          // for WaitEvent
#include "platform/gen2_arch_common/collective_states.h"

class HclCommandsGen2Arch;
class HclGraphSyncGen2Arch;
class SignalsManager;
class DeviceBufferManager;

namespace hcl
{
class ScalStream;
}

class HclCollectiveMemHandlerGen2Arch
{
public:
    HclCollectiveMemHandlerGen2Arch(int                   archStreamId,
                                    HclAddressGenerator&  addressGenerator,
                                    DeviceBufferManager&  intermediateBufferManager,
                                    HclCommandsGen2Arch&  commands,
                                    HclGraphSyncGen2Arch& graphSync);

    virtual ~HclCollectiveMemHandlerGen2Arch();

    DeviceBufferManager& getIntermediateBufferManager() { return m_intermediateBufferManager; }

    void createMemCopyCommands(CommonState&     commonState,
                               SignalsManager*  signalsManager,
                               unsigned         sliceIter,
                               BoxNumInfo&      boxNumInfo,
                               uint64_t         chunkCount,
                               hcl::ScalStream& scalStream,
                               uint32_t         dmaType,
                               bool             reductionSignalToCg,
                               uint32_t         indexOfReproBuffer,
                               bool             useSibo,
                               bool             isForScaleout,
                               bool             isRRLast,
                               e_devicePoolID   poolIdx,
                               bool             isReductionStream = false);

    SignalEvent chooseMemCopyEvent(CommonState& commonState,
                                   uint32_t     dmaType,
                                   BoxNumInfo&  boxNumInfo,
                                   bool         useSibo,
                                   bool         isForScaleout,
                                   bool         isRRLast);

    void createMemCopyCommandsNonCollective(hcl::ScalStream& scalStream,
                                            HCL_Rank         myRank,
                                            uint64_t         chunkCount,
                                            hcclDataType_t   dataType,
                                            uint64_t         recvBaseAddress,
                                            uint64_t         sendBaseAddress,
                                            uint64_t         podSize,
                                            uint8_t          apiId);

    void signalToSoViaEmptyDmaCommand(uint32_t soAddress, hcl::ScalStream& scalStream, CommonState& commonState);

    virtual void generateBaseAddressOrRRIdx(SliceState&       sliceState,
                                            unsigned int&     sliceIter,
                                            BoxNumInfo&       boxNumInfo,
                                            HCL_CollectiveOp& currentOp,
                                            uint64_t&         offset,
                                            uint64_t&         baseAddress,
                                            uint32_t&         rrIndex) = 0;

protected:
    int                   m_archStreamId;
    HclAddressGenerator&  m_addressGenerator;
    DeviceBufferManager&  m_intermediateBufferManager;
    HclCommandsGen2Arch&  m_commands;
    HclGraphSyncGen2Arch& m_graphSync;
};