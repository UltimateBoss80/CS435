#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <vector>

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

    cout << setw(5);
   
    for (int i = 0; i<ammo; i++)
    {
        cout << "💥";
        sleep_for(milliseconds(500));
    }
}

int main()
{
    /*
    int ammo = 20;
    cout << endl << endl;
    cout << "       _/﹋\\_\n"
            "       (҂`_´)\n"
            "       <,︻╦╤─ ҉ - - \n"
            "       _/﹋\\_\n";
    shoot(ammo);

    cout << endl << endl << "enemy down😎" << endl;
    */

     vector<string>man = {{"_/﹋\\_"}, {"(҂`_´)"}, {"<,︻╦╤─ ҉ - -"}, {" _/﹋\\_"} };

     /*
     for(auto it : man)
     {
        cout << it << endl;
     }
     */

    
    int ammo = 10;

    for (int i=0; i<2; i++)
    {
    cout << man[i] << endl;
    }
    cout << man[2];
    shoot(ammo);
    cout << endl << man[3];

    return 0;

   
}