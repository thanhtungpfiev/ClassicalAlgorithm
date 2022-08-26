/*
 * File: main.cpp
 * Project: SubarraySumEqualsK
 * File Created: Wednesday, 24th August 2022 9:57:43 am
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &arr, int k)
    {
        int n = arr.size(); // taking the size of the array

        int ans = 0; // ans variable to store our count

        for (int i = 0; i < n; i++) // traverse from the array
        {
            int sum = arr[i]; // provide sum with arr[i]

            if (sum == k) // if element itself equal to k, then also increment count
                ans++;

            for (int j = i + 1; j < n; j++) // now moving forward,
            {
                sum += arr[j]; // add elements with sum

                if (sum == k) // if at any point they become equal to k
                    ans++;    // increment answer
            }
        }

        return ans; // and at last, return answer
    }
};

class Solution
{
public:
    int subarraySum(vector<int> &arr, int k)
    {
        int n = arr.size(); // take the size of the array

        int prefix[n]; // make a prefix array to store prefix sum

        prefix[0] = arr[0]; // for element at index at zero, it is same

        // making our prefix array
        for (int i = 1; i < n; i++)
        {
            prefix[i] = arr[i] + prefix[i - 1];
        }

        unordered_map<int, int> mp; // declare an unordered map

        int ans = 0; // to store the number of our subarrays having sum as 'k'

        for (int i = 0; i < n; i++) // traverse from the prefix array
        {
            if (prefix[i] == k) // if it already becomes equal to k, then increment ans
                ans++;

            // now, as we discussed find whether (prefix[i] - k) present in map or not
            if (mp.find(prefix[i] - k) != mp.end())
            {
                ans += mp[prefix[i] - k]; // if yes, then add it our answer
            }

            mp[prefix[i]]++; // put prefix sum into our map
        }

        return ans; // and at last, return our answer
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}