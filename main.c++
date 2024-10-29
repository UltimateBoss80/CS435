#include <iostream>
#include <thread>
#include <chrono>

using std::this_thread::sleep_for;
using std::chrono::seconds;
using namespace std;

void MakeTop()
{
    cout << "The top is being created..."<< endl;
    sleep_for(seconds(7));
    cout << "Table top is done" << endl;
}

void MakeLegs()
{
    cout << "The legs are being created..."<< endl;
    sleep_for(seconds(5));
    cout << "Table legs are done" << endl;
}



int main()
{
    unsigned int n = thread::hardware_concurrency();
    cout << n << "Concurrent threads are supported." << endl;
    cout << "We are making a table" << endl;
    thread carpenter1 (MakeTop);
    thread carpenter2 (MakeLegs);
    cout << "Waiting for carpenters to finish" <<endl;
    carpenter1.join();
    carpenter2.join();
    cout << "Attach the legs to the table top" <<endl;
    return 0;
}