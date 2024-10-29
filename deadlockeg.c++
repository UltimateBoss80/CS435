#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using std::this_thread::sleep_for;
using std::chrono::seconds;
using namespace std;

int main()
{
    mutex m1;
    mutex m2;

    thread t1 ([&m1, &m2]
    {
        cout << endl << "t1 is acquiring m1" << endl;
        m1.lock();
        this_thread::sleep_for(chrono::milliseconds(10));
        cout << "t1 is acquiring m2" << endl;
        m2.lock();
    }
    );

    thread t2 ([&m1, &m2]
    {
        cout << endl << "t2 is acquiring m2" << endl;
        m2.lock();
        this_thread::sleep_for(chrono::milliseconds(10));
        cout << "t2 is acquiring m1" << endl;
        m1.lock();
    }
    );

    t1.join();
    t2.join();
    
    cout << endl << "Program completed" << endl;
    return 0;
}