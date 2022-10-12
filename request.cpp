// generates random IP addresses, both in and out, and random times for each request to be processed.
// o IP in
// o IP out
// o Time (integer)

#include <iostream>
#include <string>
#include <random>

#ifndef REQUEST_CPP
#define REQUEST_CPP

using namespace std;

/// @brief This is the request class which contains data about a request. A request has an IP address in, IP address out, and a process time for the request

class Request
{
public:
    /// @brief randomly generated IP in address
    string ip_in;
    /// @brief randomly generated IP out address
    string ip_out;
    /// @brief processing time of the request i.e how long it takes to process the request
    int time;
};
#endif