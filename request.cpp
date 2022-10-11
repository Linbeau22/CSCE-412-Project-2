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

struct Request
{
    string ip_in;
    string ip_out;
    int time;
};
#endif