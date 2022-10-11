#ifndef REQUEST_CPP
#include "request.cpp"
#endif

#include <vector>

using namespace std;

/// @brief This is the queue I implemented from scratch using the vector class. This queue will be used to store requests for the load balancer
class Queue
{
public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    void enqueue(Request req)
    {
        queue.push_back(req);
    }

    Request dequeue()
    {
        Request returnReq;
        if (!queue.empty())
        {
            returnReq = queue.at(0);
            queue.erase(queue.begin()); // getting rid of first element of vector
        }
        else
        {
            returnReq.ip_in = "null";
            returnReq.ip_out = "null";
            returnReq.time = 0;
        }

        return returnReq;
    }

    Request showFront()
    {
        return queue[front];
    }

    bool isEmpty()
    {
        return queue.size() == 0;
    }

    void print_queue()
    {
        for (int i = 0; i < queue.size(); i++)
        {
            cout << queue.at(i).ip_in << endl;
        }
    }

    int size()
    {
        return queue.size();
    }

private:
    vector<Request> queue;
    int front;
    int rear;
};
