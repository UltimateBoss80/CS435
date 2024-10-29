#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex myMutex;

void sharedPrint (string s, int n)
{
    myMutex.lock();
    cout << s << " " << n << endl;
    myMutex.unlock();
}

void namePrint (string s, int n)
{
    for(int i=1; i <= n; i++)
    {
        sharedPrint (s, i);
    }
}

int main()
{
    thread t1(namePrint, "Harry", 5);
    thread t2(namePrint, "Ron", 5);
    thread t3(namePrint, "Hermione", 5);

    t1.join();
    t2.join();
    t3.join();


}