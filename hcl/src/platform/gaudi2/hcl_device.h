#pragma once

#include "platform/gen2_arch_common/hcl_device.h"      // for HclDeviceGen2Arch

#include <cstddef>                                      // for NULL
#include <cstdint>                                      // for uint32_t, uint8_t
#include <map>                                          // for map
#include <set>                                          // for set
#include <unordered_set>                                // for unordered_set
#include <utility>                                      // for pair
#include <unordered_map>                                // for unordered_map

#include "hcl_global_conf.h"                            // for GCFG_* - hcl.so
#include "hcl_api_types.h"                              // for HCL_Comm, HCL_...
#include "hlthunk.h"                                    // for hlthunk_device...
#include "infra/scal/gen2_arch_common/scal_manager.h"   // for Gen2ArchScalMa...
#include "platform/gaudi2/port_mapping.h"               // for Gaudi2DevicePortMapping
#include "gaudi2_nic.h"

class ContextManager;
class Gen2ArchDevicePortMapping;
class HclDeviceConfig;
class HclDeviceControllerGen2Arch;

class HclDeviceGaudi2 : public HclDeviceGen2Arch
{
public:
    HclDeviceGaudi2(HclDeviceControllerGen2Arch& controller);  // for test only
    HclDeviceGaudi2(HclDeviceControllerGen2Arch& controller, HclDeviceConfig& deviceConfig);
    virtual ~HclDeviceGaudi2();

    virtual hlthunk_device_name getDeviceName() override;

    ContextManager& getContextManager();

    virtual uint8_t                  getPeerNic(HCL_Rank rank, HCL_Comm comm, uint8_t port) override;
    virtual unsigned                 getSenderWqeTableSize() override;
    virtual unsigned                 getReceiverWqeTableSize() override;
    virtual uint32_t                 getBackpressureOffset(uint16_t nic) override;
    const Gen2ArchDevicePortMapping& getPortMapping() override;
    virtual bool                     isScaleOutPort(uint16_t port, unsigned spotlightType = DEFAULT_SPOTLIGHT) override;
    virtual uint64_t                 getEnabledPortsMask() override;

    virtual hcclResult_t          openQpsHlsScaleOut(HCL_Comm comm, const UniqueSortedVector& outerRanks) override;
    hcclResult_t                  updateQps(HCL_Comm comm) override;
    void                          deleteCommConnections(HCL_Comm comm) override;
    virtual nics_mask_t           getAllPorts(int deviceId, unsigned spotlightType) override;

    void openQpToRemoteRanks(const HCL_Comm comm, const HCL_Rank remoteRank);

    virtual void updateDisabledPorts() override;

    virtual spHclNic allocateNic(uint32_t nic, uint32_t max_qps) override
    {
        if (GCFG_HCL_USE_IBVERBS.value())
        {
            return std::make_shared<Gaudi2IBVNic>(this, nic, max_qps, getBackpressureOffset(nic));
        }

        return std::make_shared<Gaudi2Nic>(this, nic, max_qps, getBackpressureOffset(nic));
    }
    virtual void     setGaudiDirect() override;

protected:
    hcclResult_t openQps(HCL_Comm comm, const UniqueSortedVector& ranks) override;

    void allocateQps(HCL_Comm comm, uint32_t commSize);

    ContextManager*         m_contextManager = nullptr;
    Gaudi2DevicePortMapping m_portMapping;

private:
    void          setEdmaEngineGroupSizes() override;
    HclConfigType getConfigType() override { return HLS2;};

    virtual void registerQps(HCL_Comm comm, HCL_Rank remoteRank, const QpsVector& qps, int nic = INVALID_NIC) override;
    virtual bool isSender(unsigned qpi) override;
    virtual uint32_t getQpi(HCL_Comm comm, uint8_t nic, HCL_Rank remoteRank, uint32_t qpn, uint8_t qpSet) override;
    virtual uint32_t getDestQpi(unsigned _qpi) override;

    virtual hcclResult_t openQpsHlsScaleUp(HCL_Comm comm) override;
    virtual hcclResult_t openQpsLoopback(HCL_Comm comm) override;
};