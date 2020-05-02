#ifndef ASTAR_SPEED_PLANNING_NODE_UTIL_H
#define ASTAR_SPEED_PLANNING_NODE_UTIL_H

#include <iostream>
#include <set>
#include "node.h"

namespace NodeUtil
{
    Node* findNodeOnList(const std::set<Node*>& node_list, const double s, const double t, const double v);
};


#endif //ASTAR_SPEED_PLANNING_NODE_UTIL_H
