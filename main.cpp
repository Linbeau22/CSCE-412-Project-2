#include "request.cpp"
#include "webserver.cpp"
#include "load_balancer.h"

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
    // add requests at random times
    // exit when queue is empty and all requests have complete
    int num_servers;
    cin >> num_servers;
    cout << num_servers << endl;
}