#ifndef REQUEST_CPP
#include "requests.cpp"
#endif

#include <vector>

using namespace std;

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
        if (queue.empty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }
        queue.at(rear) = req;
    }

    Request dequeue()
    {
        if (queue.empty())
        {
            return Request();
        }

        Request returnReq;
        if (front == rear)
        { // if there is only 1 element
            returnReq = queue.at(front);
            front = -1;
            rear = -1;
        }
        else
        {
            returnReq = queue.at(front);
            front++;
        }
        return returnReq;
    }

    Request showFront()
    {
        return queue[front];
    }

    bool isEmpty()
    {
        return front == rear;
    }

private:
    vector<Request> queue;
    int front;
    int rear;
};