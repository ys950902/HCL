#pragma once
#include <vector>         // for std::vector
#include <string>         // for std::string
#include "rdma/fabric.h"  // for struct fi_info

namespace hl_topo
{

/**
 * @brief Find the best provider from the providers for a given gaudi.
 * This match considers all others gaudies and hnics and produces the overall best match.
 *
 * @param providers hnic provider vector
 * @param accel current gaudi accel name
 * @return Index of best provider in the providers vector and a match type string
 */
    std::tuple<size_t, std::string> getBestProvider(const std::vector<struct fi_info *> &providers,
                                                    const std::string &accel);

}  // namespace hl_topo