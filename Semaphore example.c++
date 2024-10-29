#include <iostream>
#include <thread>
#include <semaphore.h>
#include <chrono>

using namespace std;
using std::this_thread::sleep_for;
using std::chrono::seconds;

sem_t sem;

void doThread1()
{
    sem_wait(&sem); // gain access to critical section, P
        cout << "Thread one enters critical section" << endl;
        this_thread::sleep_for(seconds(2));
        cout << "Thread one leaving critical section" << endl;
    sem_post(&sem); // release the critical section, V
}

void doThread2()
{
    sem_wait(&sem); // gain access to critical section, P
        cout << "Thread two enters critical section" << endl;
        this_thread::sleep_for(seconds(2));
        cout << "Thread two leaving critical section" << endl;
    sem_post(&sem); // release the critical section, V
}

int main()
{
    /*
    int returnValue;
    
    // address of (semaphore, shareable, inititial value)
    returnValue = sem_init(&sem, 0, 1);
    if (returnValue == -1)
    {
        cout << endl << "Error: semaphore note initialized" << endl;
    }
    */ // Both above and below if statements are the samething

    if (sem_init(&sem, 0, 1) != 0)
    {
        cout << endl << "Error: semaphore note initialized" << endl;
    }

    thread t1(doThread1);
    thread t2(doThread2);

    t1.join();
    t2.join();

    sem_destroy(&sem);



    return 0;
}