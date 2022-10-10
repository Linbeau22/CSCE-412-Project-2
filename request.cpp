// generates random IP addresses, both in and out, and random times for each request to be processed.
// o IP in
// o IP out
// o Time (integer)

// request class holds a request
// need a queue of type Request
#include <iostream>
#include <string>
#include <random>

#ifndef REQUEST_CPP
#define REQUEST_CPP

using namespace std;

struct Request
{
    string ip_in;
    string ip_out;
    int time;
};
#endif