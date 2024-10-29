#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>


using namespace std;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

void shoot(int n);

void reload (int ammo)
{
    cout << "reloading..." << endl;
    sleep_for(milliseconds(3000));
    ammo += 10;
    shoot(ammo);

}
void shoot(int ammo)
{
    if (ammo == 0)
    {
        cout << "no ammo in clip bro!" << endl;
        reload(ammo);
    }

    cout << setw(25);
   
    for (int i = 0; i<ammo; i++)
    {
        cout << "💥";
        sleep_for(milliseconds(500));
    }
}

int main()
{
    int ammo = 20;
    cout << endl << endl;
    cout << "_______/]_________[\\_____ \n"
            "|  ____   ___|-----------|===== \n" 
            "|_/    / /_| | \n"
            "      /_/  | |";
    shoot(ammo);

    cout << endl << endl << "enemy down😎" << endl;

    return 0;

}