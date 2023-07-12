/*
 * File: main.cpp
 * Project: HappyNumber
 * File Created: Wednesday, 17th August 2022 10:02:41 am
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
    int getNext(int n)
    {
        int result = 0;
        while (n)
        {
            int p = n % 10;
            result += p * p;
            n = n / 10;
        }
        return result;
    }
    bool isHappy(int n)
    {
        unordered_set<int> ht;
        while (n != 1 && (ht.find(n) == ht.end()))
        {
            ht.insert(n);
            n = getNext(n);
        }
        return n == 1;
    }
};

class Solution
{
public:
    int getNext(int n)
    {
        int result = 0;
        while (n)
        {
            int p = n % 10;
            result += p * p;
            n = n / 10;
        }
        return result;
    }
    bool isHappy(int n)
    {
        int slowPtr = n;
        int fastPtr = getNext(n);
        while (fastPtr != 1 && slowPtr != fastPtr)
        {
            slowPtr = getNext(slowPtr);
            fastPtr = getNext(getNext(fastPtr));
        }
        return fastPtr == 1;
    }
};

class Solution
{
public:
    int getNext(int n)
    {
        int result = 0;
        while (n)
        {
            int p = n % 10;
            result += p * p;
            n = n / 10;
        }
        return result;
    }
    bool isHappy(int n)
    {
        unordered_set ht{4, 16, 37, 58, 89, 145, 42, 20};
        while (n != 1 && ht.find(n) == ht.end())
        {
            n = getNext(n);
        }
        return n == 1;
    }
};

class Solution
{
public:
    int getNext(int n)
    {
        int result = 0;
        while (n)
        {
            int p = n % 10;
            result += p * p;
            n = n / 10;
        }
        return result;
    }
    bool isHappy(int n)
    {
        while (n != 1 && n != 4)
        {
            n = getNext(n);
        }
        return n == 1;
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: n = 19
    // Output: true
    // Explanation:
    // 12 + 92 = 82
    // 82 + 22 = 68
    // 62 + 82 = 100
    // 12 + 02 + 02 = 1

    // Input: n = 2
    // Output: false
    return 0;
}