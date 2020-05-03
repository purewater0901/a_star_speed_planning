#include <iostream>
#include <set>
#include <chrono>
#include <cstring>
#include <fstream>
#include "node.h"
#include "node_util.h"

double calcSpeedLimit(const double s)
{
    return 10.0;
}

double calcRefSpeed(const double s)
{
    return 3.0;
}

bool isOccupied(const double obs_s_min,
                const double obs_s_max,
                const double obs_t_min,
                const double obs_t_max,
                double s,
                double t)
{
    return obs_s_min <= s && s <= obs_s_max && obs_t_min < t && t < obs_t_max;
}

int main() {

    std::string filename = "../result.csv";
    std::ofstream writing_file;
    writing_file.open(filename, std::ios::out);
    writing_file << "s" << "," << "t" << std::endl;
    double weight_v = 1.0;
    double goal_s = 40.0;
    double t_max = 20.0;
    double dt = 0.1;
    double a_max = 1.0;
    std::vector<double> da_list = {a_max, 0.0, -a_max};

    //Obstacle information
    double obs_t_min = 4.0;
    double obs_t_max = 10.0;
    double obs_s_min = 10.0;
    double obs_s_max = 14.0;

    //node list
    std::set<Node*> open_node_list;
    std::set<Node*> closed_node_list;

    Node start_node(0.0, 0.0, 0.0, goal_s);
    open_node_list.insert(&start_node);

    std::chrono::system_clock::time_point  start, end;
    start = std::chrono::system_clock::now(); //start
    while(true)
    {
        if(open_node_list.empty())
        {
            std::cout << "We cannot find a solution" << std::endl;
            break;
        }

        //choose least cost node
        Node* current_node = *open_node_list.begin();
        for(Node* node : open_node_list)
            if(node->getScore() <= current_node->getScore())
                current_node = node;

        //check current node is in the goal_s
        if(current_node->isGoal(goal_s))
        {
            end = std::chrono::system_clock::now();  // end time
            double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
            std::cout << "Calculation Time: " << elapsed << std::endl;

            std::cout << "We reached the goal" << std::endl;
            while(current_node != nullptr)
            {
                //std::cout << "s: " << current_node->s_ << std::endl;
                //std::cout << "t: " << current_node->t_ << std::endl;
                std::cout << "v: " << current_node->v_ << std::endl;
                writing_file << current_node->s_ << "," << current_node->t_ << std::endl;

                current_node = current_node->parent_node_;
            }

            break;
        }

        closed_node_list.insert(current_node);
        open_node_list.erase(std::find(open_node_list.begin(), open_node_list.end(), current_node));

        for(double da : da_list)
        {
            double new_v = current_node->v_ + da*dt;
            double new_t = current_node->t_ + dt;
            double new_s = current_node->s_ + current_node->v_*dt + 0.5*da*dt*dt;

            bool isCollide = isOccupied(obs_s_min, obs_s_max, obs_t_min, obs_t_max, new_s, new_t);
            if(-1e-6 < new_v && new_v<= calcSpeedLimit(new_s) && new_t <= t_max && !isCollide)
            {
                Node* closed_node = NodeUtil::findNodeOnList(closed_node_list, new_s, new_t, new_v);
                if(closed_node != nullptr)
                    continue;

                double reference_v = calcRefSpeed(new_s);
                double additional_cost = weight_v * std::pow((new_v - reference_v), 2);
                //double additional_cost = 0.5*std::pow((new_s - goal_s), 2);
                double new_cost = current_node->actual_cost_ + additional_cost;

                Node* successor = NodeUtil::findNodeOnList(open_node_list, new_s, new_t, new_v);
                if(successor==nullptr)
                {
                    //We don't have this node in the open node list
                    successor = new Node(new_s, new_t, new_v, goal_s, current_node);
                    successor->actual_cost_ = new_cost;
                    open_node_list.insert(successor);
                }
                else if(new_cost < successor->actual_cost_)
                {
                    /*
                       We already has this node in the open node list, and the node cost is lower than original,
                       so we will update the cost
                     */
                    successor->parent_node_ = current_node;
                    successor->actual_cost_ = new_cost;
                }
            }
        }
    }

    return 0;
}
