#include <iostream>
#include <thread>
#include <semaphore.h>

using namespace std;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

sem_t conveyerBelt;

void placeItem(int items, int time)
{
    for (int i = 1; i <= items; i++)
    {
        sem_wait(&conveyerBelt);
        cout << "Item " << i << " placed." << endl;
        this_thread::sleep_for(milliseconds(time));
        sem_post(&conveyerBelt);
    }
}

void removeItem(int items, int time)
{
    for (int i = 1; i <= items; i++)
    {
        sem_wait(&conveyerBelt);
        cout << "Item " << i << " removed." << endl;
        this_thread::sleep_for(milliseconds(time));
        sem_post(&conveyerBelt);
    }
    
}
int main()
{
    int items = 0;
    int time = 0;

    if (sem_init(&conveyerBelt, 0, 1) != 0)
    {
        cout << "Error: Semaphore not initialized" << endl;
        return -1;
    }

    cout << "Enter your desired ammount of items: ";
    cin >> items;
    if (items <=0)
    {
        cout << "Error: Number of items must be positive";
        sem_destroy(&conveyerBelt);
        return -1;
    }

    cout << endl << "Enter your desired time delay in milliseconds: ";
    cin >> time;
    if (time < 0)
    {
        cout << "Error: Delayed time can't be negative";
        sem_destroy(&conveyerBelt);
        return -1;
    }

    thread t1(placeItem, items, time);
    thread t2(removeItem, items, time);

    t1.join();
    t2.join();

    sem_destroy(&conveyerBelt);

    return 0;


}