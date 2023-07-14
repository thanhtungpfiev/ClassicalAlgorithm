/*
 * File: main.cpp
 * Project: FindThePairInTwoArrays
 * File Created: Wednesday, 1st June 2022 2:48:35 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<pair<int, int>> allPairs(int A[], int B[], int N, int M, int X)
{
    unordered_set<int> hs;
    vector<pair<int, int>> result;
    for (int i = 0; i < M; ++i)
    {
        hs.insert(B[i]);
    }
    for (int i = 0; i < N; ++i)
    {
        auto it = find(hs.begin(), hs.end(), X - A[i]);
        if (it != hs.end())
        {
            result.push_back(pair<int, int>(A[i], *it));
        }
    }
    sort(result.begin(), result.end());
    return result;
}

int main(int argc, char **argv)
{
    int A[] = {1, 2, 4, 5, 7};
    int B[] = {5, 6, 3, 4, 8};
    int X = 9;
    vector<pair<int, int>> result = allPairs(A, B, 5, 5, X);
    for (const auto &e : result)
    {
        cout << e.first << " " << e.second << endl;
    }
    int A1[] = {-1, -2, 4, -6, 5, 7};
    int B1[] = {6, 3, 4, 0};
    int X1 = 8;
    vector<pair<int, int>> result1 = allPairs(A1, B1, 6, 4, X1);
    for (const auto &e : result1)
    {
        cout << e.first << " " << e.second << endl;
    }
}
