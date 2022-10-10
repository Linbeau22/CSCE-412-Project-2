#include "webserver.cpp"
#include "request.cpp"
#include "load_balancer.h"

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

Request createRandomReq()
{
    string ip_in;
    string ip_out;
    Request returnReq;

    // generate random ip_in address
    ip_in = to_string((rand() % 256)) + "." + to_string((rand() % 256)) + "." + to_string((rand() % 256)) + "." + to_string((rand() % 256));
    ip_out = to_string((rand() % 256)) + "." + to_string((rand() % 256)) + "." + to_string((rand() % 256)) + "." + to_string((rand() % 256));

    // assigning the attributes of the request
    returnReq.ip_in = ip_in;
    returnReq.ip_out = ip_out;
    returnReq.time = rand() % 1000; // up to 1000 units of time to process
    return returnReq;
}

int main()
{
    // add requests at random times
    // exit when queue is empty and all requests have complete
    const int CLOCK_CYCLES = 10000;
    int num_servers;
    cout << "Enter number of servers: ";
    cin >> num_servers;

    int initial_queue_size = num_servers * 2;

    // Queue q;
    // Request r = createRandomReq();
    // Request p = createRandomReq();
    // q.enqueue(r);
    // q.enqueue(p);

    // q.print_queue();

    // random time
    srand(time(0));
    Load_Balancer load_balancer;           // creating load balancer
    WebServer web_server_arr[num_servers]; // creating array that holds webservers

    for (int i = 0; i < initial_queue_size; i++)
    {
        load_balancer.addReq(createRandomReq());
    } // create random requests and add them to the load balancer

    cout << "Starting queue size: " << load_balancer.size() << endl;

    // generating a full queue of webservers
    for (int i = 0; i < num_servers; i++)
    {
        string server_name;
        server_name = (char)(i + 65);
        WebServer ws(server_name);

        ws.addReq(load_balancer.getReq(), load_balancer.getTime());

        web_server_arr[i] = ws;
    }

    while (load_balancer.getTime() < CLOCK_CYCLES)
    {
        int curr_time = load_balancer.getTime();
        int index = curr_time % num_servers;

        // if server at index is done with its request, give it another request from the load balancer
        if (web_server_arr[index].isDone(curr_time))
        { // if webserver is done, give next request of the queue
            Request req = web_server_arr[index].getReq();
            string server_name = web_server_arr[index].getServerName();
            cout << "Time " << curr_time << ": server " << server_name << " processed request from " << req.ip_in << " to " << req.ip_out << endl;
            web_server_arr[index].addReq(load_balancer.getReq(), curr_time);
        }

        // generate new requests at random times (when rand() % 10 == 0)
        if (rand() % 10 == 0)
        {
            Request req = createRandomReq();
            load_balancer.addReq(req);
        }

        load_balancer.incrementTime();
    }

    cout << "Ending queue size: " << load_balancer.size() << endl;
}