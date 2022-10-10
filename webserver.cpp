// o Takes requests from the Load Balancer
// o Process the requests
// o Asks for another

// create number of webservers requested (user input)
#include <iostream>
#include <string>
#include "requests.cpp"

using namespace std;

class WebServer
{

public:
    WebServer()
    { // default constructor
        rqStartTime = 0;
        serverName = " ";
    }

    WebServer(string serverName) // constructor with inputted server name
    {
        rqStartTime = 0;
        this->serverName = serverName;
    }

    Request getRequest()
    {
        return req;
    }

    string getServerName()
    {
        return serverName;
    }

    bool isDone(int currTime)
    {
        if (currTime > reqStartTime + req.time)
            return true;
        return false;
    }

    void addRequest(Request rq, int currTime)
    {
        this->request = rq;
        reqStartTime = currTime;
    }

private:
    int num_servers;
    Request req; // each server has a request they are dealing with
    int reqStartTime;
    string serverName;
};