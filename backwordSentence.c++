#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    string sentence = "If you said a sentence backwords does that mean you said it back words";
    int m; //ignore this, testing git
    vector<string>words;
    stringstream ss(sentence);
    string word;

    while(ss >> word)
    {
        words.push_back(word);
    }

    for(auto it = words.rbegin(); it != words.rend(); it++)
    {
        cout << *it << " ";
    }

    return 0;
    
}
