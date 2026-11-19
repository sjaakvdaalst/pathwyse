#include "open_request.h"

OpenRequest::OpenRequest() {
    name = "Open Request";
    init_value = 0;
    lower_bound = 0;
    upper_bound = 1;
}

void OpenRequest::init(int origin, int destination) {
    this->destination = destination;
}

int OpenRequest::extend(int current_value, int i, int j, bool direction) {
    int dest_node = direction ? j : i;
    return current_value + data->getNodeCost(dest_node);
}

int OpenRequest::join(int current_value_forward, int current_value_backward, int i, int j){
    return current_value_forward + current_value_backward;
}

int OpenRequest::join(int current_value_forward, int current_value_backward, int node){
    return current_value_forward + current_value_backward - data->getNodeCost(node);
}

//Infeasible: delivery before pickup (-1), pickup of an open request (2), route ends with the request open
bool OpenRequest::isFeasible(int current_value, int current_node, double bounding, bool direction) {
    if(current_value < lower_bound or current_value > upper_bound)
        return false;
    if(current_node == destination and current_value != 0)
        return false;
    return true;
}