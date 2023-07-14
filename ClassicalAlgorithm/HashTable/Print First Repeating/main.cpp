/*
 * File: main.cpp
 * Project: PrintFirstRepeating
 * File Created: Tuesday, 26th July 2022 4:06:19 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>

using namespace std;

void printFirstRepeating(std::vector<int> &arr)
{
    int i;
    int size = arr.size();
    CountMap<int> *hs = new CountMap<int>();
    for (i = 0; i < size; i++)
    {
        hs->add(arr[i]);
    }
    for (i = 0; i < size; i++)
    {
        hs->remove(arr[i]);
        if (hs->containsKey(arr[i]))
        {
            std::cout << "First Repeating number is : " << arr[i] << std::endl;
            return;
        }
    }
}

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}