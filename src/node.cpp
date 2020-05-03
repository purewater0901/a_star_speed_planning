#include "node.h"

Node::Node(const double s,
           const double t,
           const double v,
           const double goal_s,
           Node* Parent) :
           s_(s),
           v_(v),
           t_(t),
           actual_cost_(0.0),
           parent_node_(Parent)
{
    heuristic_cost_ = 10*std::pow(s - goal_s, 2);
}

bool Node::isGoal(const double goal_s)
{
    return std::fabs(goal_s - s_) < 1e-6 || goal_s < s_;
}

