#ifndef REQUEST_CPP
#include "request.cpp"
#endif

#include <vector>

using namespace std;

/// @brief This is the queue I implemented from scratch using the vector class. This queue will be used to store requests for the load balancer
class Queue
{
public:
    /// @brief  default constructor
    Queue()
    {
    }

    /// @brief Adds a request to the queue
    /// @param req Request
    void enqueue(Request req)
    {
        queue.push_back(req);
    }

    /// @brief Removes a request from the queue if the queue is not empty
    /// @return returns the request being dequeued
    Request dequeue()
    {
        Request returnReq;
        if (!queue.empty())
        {
            returnReq = queue.at(0);
            queue.erase(queue.begin()); /// getting rid of first element of vector
        }
        else
        {
            returnReq.ip_in = "null";
            returnReq.ip_out = "null";
            returnReq.time = 0;
        }

        return returnReq;
    }

    /// @brief Checks if the request queue is empty
    /// @return true if the queue is empty, false if not
    bool isEmpty()
    {
        return queue.size() == 0;
    }

    /// @brief Prints the queue: used for debugging
    void print_queue()
    {
        for (int i = 0; i < queue.size(); i++)
        {
            cout << queue.at(i).ip_in << endl;
        }
    }

    /// @brief Returns the size of the request queue
    /// @return size of the queue
    int size()
    {
        return queue.size();
    }

private:
    /// @brief queue that holds requests in form of a vector
    vector<Request> queue;
};
