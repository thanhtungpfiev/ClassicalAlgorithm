/*
 * File: main.cpp
 * Project: PrintRepeating
 * File Created: Tuesday, 26th July 2022 4:01:41 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>

using namespace std;

void printRepeating(std::vector<int> &arr)
{
    std::unordered_set<int> hs;
    std::cout << "Repeating elements are:";
    for (auto val : arr)
    {
        if (hs.find(val) != hs.end())
        {
            std::cout << val << " ";
        }
        else
        {
            hs.insert(val);
        }
    }
}

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}