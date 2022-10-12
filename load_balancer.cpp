// o Queue of requests
// o Keeps track of time.
// manages webservers and request queue
#ifndef LOAD_BALANCER_H
#include "Load_Balancer.h"
#endif

#include <iostream>

/// @brief returns the system time
/// @return system time
int Load_Balancer::getTime()
{
    return systemTime;
}

/// @brief increments the system time by 1
void Load_Balancer::incrementTime()
{
    systemTime++;
}

void Load_Balancer::addReq(Request req)
{
    reqQueue.enqueue(req); /// add the request to the request queue
    systemTime++;          /// increment the time because it takes time to add to the queue
}

/// @brief returns the request at the end of the queue and dequeues it from the queue
/// @return request that's dequeued
Request Load_Balancer::getReq()
{
    systemTime++;
    if (!reqQueue.isEmpty())
    {
        Request req = reqQueue.dequeue();
        return req;
    }
}

/// @brief prints the elements in the queue: used for debugging
void Load_Balancer::print_queue()
{
    reqQueue.print_queue();
}

/// @brief Checks to see if the queue of requests is empty
/// @return true if queue is empty, false if not
bool Load_Balancer::isEmpty()
{
    return reqQueue.isEmpty();
}

/// @brief  returns the size of the request queue
/// @return size of the queue
int Load_Balancer::size()
{
    return reqQueue.size();
}
