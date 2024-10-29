#include <iostream>
#include <semaphore.h>
#include <fcntl.h>

using namespace std;

int main()
{
    char * name = "\mySemaphore";
    sem_t * sema;

    // if the semaphore with the name does not exist,
    // then create it with a value of 1
    sema = sem_open(name, O_CREAT, O_RDWR, 1);

    // wait on semaphore sema and decrease it by 1  (P operation)
    sem_wait(sema);

        cout << endl << "Inside of critical section" << endl;

    // add 1 to sema and signal (V operation)
    sem_post(sema);

    sem_close(sema);
    sem_unlink(name);

    return 0;
}