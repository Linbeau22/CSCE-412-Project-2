// o Queue of requests
// o Keeps track of time.
// manages webservers and request queue
#ifndef LOAD_BALANCER_H
#include "Load_Balancer.h"
#endif

#include <iostream>

int Load_Balancer::getTime()
{
    return systemTime;
}

void Load_Balancer::incrementTime()
{
    systemTime++;
}

void Load_Balancer::addReq(Request req)
{
    reqQueue.enqueue(req); // add the request to the request queue
    systemTime++;          // increment the time because it takes time to add to the queue
}

Request Load_Balancer::getReq()
{
    systemTime++;
    if (!reqQueue.isEmpty())
    {
        Request req = reqQueue.dequeue();
        return req;
    }
}

void Load_Balancer::print_queue()
{
    reqQueue.print_queue();
}

bool Load_Balancer::isEmpty()
{
    return reqQueue.isEmpty();
}

int Load_Balancer::size()
{
    return reqQueue.size();
}
