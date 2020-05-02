//
// Created by 清水豊禾 on 2020/05/02.
//

#include "node_util.h"

Node* NodeUtil::findNodeOnList(const std::set<Node*>& node_list, const double s, const double t, const double v)
{
    for(Node* node : node_list)
    {
        if(std::fabs(node->s_-s) < 1e-6 && std::fabs(node->t_-t) < 1e-6 && std::fabs(node->v_-v) < 1e-6)
            return node;
    }
    return nullptr;
}
