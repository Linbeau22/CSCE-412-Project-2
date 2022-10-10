// o Takes requests from the Load Balancer
// o Process the requests
// o Asks for another

// create number of webservers requested (user input)
#ifndef REQUEST_CPP
#include "request.cpp"
#endif

#include <iostream>
#include <string>
#include "request.cpp"

using namespace std;

class WebServer
{

public:
    WebServer()
    { // default constructor
        reqStartTime = 0;
        serverName = " ";
    }

    WebServer(string serverName) // constructor with inputted server name
    {
        reqStartTime = 0;
        this->serverName = serverName;
    }

    Request getReq()
    {
        return req;
    }

    string getServerName()
    {
        return serverName;
    }

    bool isDone(int currTime)
    {
        if (currTime >= reqStartTime + req.time)
            return true;
        return false;
    }

    void addReq(Request rq, int currTime)
    {
        this->req = rq;
        reqStartTime = currTime;
    }

private:
    int num_servers;
    Request req; // each server has a request they are dealing with
    int reqStartTime;
    string serverName;
};