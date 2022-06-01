/*
 * File: main.cpp
 * Project: SearchElementInABitonicArray
 * File Created: Wednesday, 1st June 2022 3:14:05 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int SearchBotinicArrayMaxIndex(std::vector<int> &arr)
{
    int l = 0;
    int r = arr.size() - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if ((r == l + 1) && arr[l] >= arr[r])
            return l;

        if ((r == l + 1) && arr[l] < arr[r])
            return r;

        if (arr[m] > arr[m + 1] && arr[m] > arr[m - 1])
            return m;

        if (arr[m] > arr[m + 1] && arr[m] < arr[m - 1])
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}

int SearchBitonicArray(std::vector<int> &data, int key)
{
    int maxIndex = SearchBotinicArrayMaxIndex(data);
    if (key > data[maxIndex])
    {
        return -1;
    }
    auto it = lower_bound(data.begin(), data.begin() + maxIndex, key);
    if (it != data.end() && *it == key) {
        return distance(data.begin(), it);
    }
    it = lower_bound(data.begin() + maxIndex + 1, data.end(), key, std::greater<int>());
    if (it != data.end() && *it == key) {
        return distance(data.begin(), it);
    }
    return -1;
}


int main(int argc, char **argv)
{
    vector<int> arr = {-3, 9, 18, 20, 17, 5, 1};
    int key = 20;
    cout << SearchBitonicArray(arr, key) << endl;
    key = -3;
    cout << SearchBitonicArray(arr, key) << endl;
    key = 5;
    cout << SearchBitonicArray(arr, key) << endl;
    key = 1;
    cout << SearchBitonicArray(arr, key) << endl;
    arr = {5, 6, 7, 8, 9, 10, 3, 2, 1};
    key = 30;
    cout << SearchBitonicArray(arr, key) << endl;

    return 0;
}