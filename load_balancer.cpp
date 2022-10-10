// o Queue of requests
// o Keeps track of time.
// manages webservers and request queue
#ifndef LOADBALANCER_H
#include "load_balancer.h"
#endif
#include <iostream>

int LoadBalancer::getTime()
{
    return systemTime;
}

void LoadBalancer::addReq(Request req)
{
    reqQueue.enqueue(req); // add the request to the request queue
    systemTime++;          // increment the time because it takes time to add to the queue
}

Request LoadBalancer::getReq()
{
    systemTime++;
    if (!reqQueue.isEmpty())
    {
        Request req = reqQueue.dequeue();
        return req;
    }
}

bool LoadBalancer::isEmpty()
{
    return reqQueue.isEmpty();
}