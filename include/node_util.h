#ifndef ASTAR_SPEED_PLANNING_NODE_UTIL_H
#define ASTAR_SPEED_PLANNING_NODE_UTIL_H

#include <iostream>
#include <set>
#include "node.h"
#include "hastar_node.h"

namespace NodeUtil
{
    Node* findNodeOnList(const std::set<Node*>& node_list, const double s, const double t, const double v);
};

namespace HAStarNodeUtil
{
    HAStarNode* findNodeOnList(const std::set<HAStarNode*>& node_list, const int s_d, const int t_d, const int v_d);
}


#endif //ASTAR_SPEED_PLANNING_NODE_UTIL_H
