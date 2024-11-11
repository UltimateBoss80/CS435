#include <iostream>
#include <semaphore.h>
#include <fcntl.h>
using namespace std;

#ifdef _WIN32
    #include <windows.h>
#elif __linux__
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <pthread.h>
#elif __APPLE__
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <pthread.h>
#endif

int main()
{
    #ifdef _WIN32
        HANDLE critSec;
        // Create a named semaphore in Windows using CreateSemaphore
        critSec = CreateSemaphore(NULL, 1, 1, "mySemaphore");
        if (critSec == NULL) {
            cerr << "Failed to create semaphore" << endl;
            return 1;
        }

        // Enter critical section
        WaitForSingleObject(critSec, INFINITE);

        //Get and display process ID
        DWORD processID = GetCurrentProcessId();
        cout << "Process ID: " << processID << endl;

        // Get and display the system page size
        SYSTEM_INFO sysInfo;
        GetSystemInfo(&sysInfo); //Get system information
        cout << "System page size: " << sysInfo.dwPageSize << " bytes" << endl;

        // Make a directory
        LPCSTR dirName = "newFolder";
        if (CreateDirectory(dirName, NULL) || ERROR_ALREADY_EXISTS == GetLastError())
        {
            cout << "Directory created successfully (or already exists)." << endl;
        }
        else 
        {
            cerr << "Failed to create directory." << endl;
        }

        // Exit critical section
        ReleaseSemaphore(critSec, 1, NULL);

        // Clean up semaphore
        CloseHandle(critSec);
    #endif

    #if defined(__linux__) || defined(__APPLE__)
        // Create a named semaphore
        sem_t* critSec = sem_open("/my_semaphore", O_CREAT, S_IRUSR | S_IWUSR, 1);

        if (critSec == SEM_FAILED) 
        {
            cerr << "Failed to create semaphore" << endl;
            return 1;
        }
        // Enter critical section
        sem_wait(critSec);

        //Get and display process ID
        pid_t processID = getpid();
        cout << "Process ID: " << processID << endl;

        // Get and display the system page size
        long pageSize = getpagesize();
        cout << "System page size: " << pageSize << " bytes" << endl;

        // Make a directory
        const char* dirName = "newFolder";
        if (mkdir(dirName, 0777) == 0)
        {
            cout << "Directory created successfully" << endl;
        }
        else 
        {
            cerr << "Failed to create directory." << endl;
        }
        // Exit critical section
        sem_post(critSec);

        // Clean up semaphore
        sem_close(critSec);
        sem_unlink("/my_semaphore");
    #endif

    return 0;
}