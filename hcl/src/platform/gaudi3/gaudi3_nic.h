#pragma once

#include "platform/gen2_arch_common/gen2arch_nic.h"

class Gaudi3Nic : public Gen2ArchNic
{
public:
    Gaudi3Nic(IHclDevice* device, int nic, uint32_t nQPN, uint32_t bp);

    uint32_t nic2QpOffset = -1;

protected:
    void _get_app_params_();
};

class Gaudi3IBVNic : public Gen2ArchIBVNic
{
public:
    uint32_t nic2QpOffset = -1;

    Gaudi3IBVNic(IHclDevice* device, uint32_t nic, uint32_t nQPN, bool scaleOut, uint32_t bp);

    virtual void init() override;
};