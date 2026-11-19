/*
Addition of resource class for PDPTW functionality.

Open Request resource for PDPTW: one resource per pickup-delivery request.
Value 1 while the request is picked up and not yet delivered, else 0.
Node consumption: +1 at the pickup, -1 at the delivery, 0 elsewhere.

Enforces:
- pickup precedes delivery
- no pickup while its request is open
- the route cannot end with an open request

Used together with the standard resources time windows and capacity.
*/


#ifndef OPEN_REQUEST_H
#define OPEN_REQUEST_H

#include "resource.h"

class OpenRequest: public Resource {

public:
    OpenRequest();
    ~OpenRequest() = default;

    void init(int origin, int destination) override;
    int extend(int current_value, int i, int j, bool direction) override;
    int join(int current_value_forward, int current_value_backward, int i, int j) override;
    int join(int current_value_forward, int current_value_backward, int node) override;
    bool isFeasible(int current_value, int current_node, double bounding, bool direction) override;
    int getDeliveryNode() {return delivery_node;}

private:
    int destination;
    int delivery_node;
};

#endif