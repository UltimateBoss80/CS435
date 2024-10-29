#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <sstream>
#include <unordered_map>

using namespace std;
using std::chrono::seconds;
using std::this_thread::sleep_for;

// Output each word in a senctence after a second using a vector and then check its frequency with hash table

int main()
{
    string sentence = "In life you have to learn to think about the next step When you do so you begin to see the cosmos";
    int bro;
    vector<string>words;
    stringstream ss(sentence); // Used for breaking up words.
    string word;
    unordered_map<string, int>freq;

   while (ss >> word) // Storing indivual words.
    {
        words.push_back(word);

    }
    
    for(auto s : words)
    {
        freq[s]++; // check how many times an individual word appears
        cout << s << " " << freq[s]<< endl;
        sleep_for(seconds(1));
    } 

    // Check the most frequent word

    int max = 0;
    string mostFreqWord;
    for (auto itr = freq.begin(); itr != freq.end(); itr++)
    {
        if (itr->second > max)
        {
            max = itr->second;
            mostFreqWord = itr->first;
            
        }
    }

    cout << "Most frequent word is: " << mostFreqWord << endl;


    return 0;

}
    