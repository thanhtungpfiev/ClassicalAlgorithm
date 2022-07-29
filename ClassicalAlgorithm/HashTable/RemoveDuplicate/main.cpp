/*
 * File: main.cpp
 * Project: RemoveDuplicate
 * File Created: Tuesday, 26th July 2022 3:27:38 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>

using namespace std;

void removeDuplicate(std::string &str)
{
    int index = 0;
    std::unordered_set<char> hs;
    for (auto ch : str)
    {
        if (hs.find(ch) == hs.end())
        {
            str[index++] = ch;
            hs.insert(ch);
        }
    }
    str[index] = '\0';
}

class Solution
{
public:
    int remove_duplicate(int a[], int n)
    {
        // code here
        if (n == 0)
        {
            return 0;
        }
        int i = 0;
        for (int j = 1; j < n; ++j)
        {
            if (a[j] != a[i])
            {
                i++;
            }
            a[i] = a[j];
        }
        return i + 1;
    }
};

class Solution
{
public:
    int remove_duplicate(int a[], int n)
    {
        // code here
        set<int> ht;
        for (int i = 0; i < n; ++i)
        {
            if (ht.find(a[i]) == ht.end())
            {
                ht.insert(a[i]);
            }
        }
        int i = 0;
        for (auto it = ht.begin(); it != ht.end(); ++it)
        {
            a[i++] = *it;
        }
        return ht.size();
    }
};

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}