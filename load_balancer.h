#define LOAD_BALANCER_H

#ifndef REQUEST_CPP
#include "request.cpp"
#endif

#include "queue.cpp"

class Load_Balancer
{
public:
    // default constructor
    Load_Balancer()
    {
        systemTime = 0;
    }

    int getTime();

    void incrementTime();

    void addReq(Request req);

    bool isEmpty();

    Request getReq();

    void print_queue();

    int size();

private:
    int systemTime;
    Queue reqQueue;
};
