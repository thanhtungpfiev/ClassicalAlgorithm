/*
 * File: main.cpp
 * Project: AnagramSolver
 * File Created: Tuesday, 26th July 2022 3:18:31 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>

using namespace std;

bool isAnagram(std::string &str1, std::string &str2)
{
    int size1 = str1.size();
    int size2 = str2.size();
    if (size1 != size2)
        return false;
    CountMap<char> *cm = new CountMap<char>();
    for (auto ch : str1)
        cm->add(ch);
    for (auto ch : str2)
        cm->remove(ch);
    return (cm->size() == 0);
}

class Solution
{
public:
    // Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b)
    {

        // Your code here
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    }
};

class Solution
{
public:
    // Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b)
    {

        // Your code here
        unordered_map<char, int> ht;
        for (auto c : a)
        {
            ht[c]++;
        }
        for (auto c : b)
        {
            ht[c]--;
        }
        for (auto it : ht)
        {
            if (it.second != 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}