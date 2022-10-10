#define LOADBALANCER_H

#ifndef REQUEST_CPP
#include "requests.cpp"
#endif

#include "queue.cpp"

class LoadBalancer
{
public:
    // default constructor
    LoadBalancer()
    {
        systemTime = 0;
    }

    int getTime();

    void addReq(Request req);

    bool isEmpty();

    Request getReq();

private:
    int systemTime;
    Queue reqQueue();
};