/*
 * File: main.cpp
 * Project: FirstRepeatedElementInTheArray
 * File Created: Thursday, 2nd June 2022 5:52:55 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int data[], int n)
    {
        // code here
        unordered_map<int, int> ht;
        for (int i = 0; i < n; ++i)
        {
            ht[data[i]]++;
        }
        for (int i = 0; i < n; ++i)
        {
            if (ht[data[i]] > 1)
            {
                return i + 1;
            }
        }
        return -1;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    int arr[] = {7, 4, 0, 9, 4, 8, 8, 2, 4, 5, 5, 1};
    cout << sl.firstRepeated(arr, 12) << endl;
    return 0;
}