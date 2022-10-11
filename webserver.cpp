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

/// @brief This is the webserver class, which takes requests from the load balancer, processes the requests, and asks for another request once it finishes processing its current request

class WebServer
{

public:
    WebServer()
    { // default constructor
        reqStartTime = 0;
        serverName = " ";
    }

    /// @brief This is the constructor, which takes in the servername and initializes the request start time to 0
    /// @param serverName string server name
    WebServer(string serverName) // constructor with inputted server name
    {
        reqStartTime = 0;
        this->serverName = serverName;
    }

    /// @brief This just grabs the request pertaining to the selected server
    /// @return
    Request getReq()
    {
        return req;
    }

    /// @brief This just returns the selected servername
    /// @return
    string getServerName()
    {
        return serverName;
    }

    /// @brief This checks if the request is done processing by taking in the current time as a paramter
    /// @param currTime comparing current time to the request start time + request process time
    /// @return
    bool isDone(int currTime)
    {
        if (currTime >= reqStartTime + req.time)
            return true;
        return false;
    }

    /// @brief This assigns a new request to the server
    /// @param rq The new request
    /// @param currTime current time is request start time
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