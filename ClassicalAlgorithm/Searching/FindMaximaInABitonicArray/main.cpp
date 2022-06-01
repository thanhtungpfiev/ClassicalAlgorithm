/*
 * File: main.cpp
 * Project: FindMaximaInABitonicArray
 * File Created: Wednesday, 1st June 2022 3:06:17 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>

using namespace std;

int SearchBotinicArrayMax(std::vector<int> &arr)
{
    int l = 0;
    int r = arr.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;

        if ((r == l + 1) && arr[l] >= arr[r])
            return arr[l];

        if ((r == l + 1) && arr[l] < arr[r])
            return arr[r];

        if (arr[m] > arr[m + 1] && arr[m] > arr[m - 1])
            return arr[m];

        if (arr[m] > arr[m + 1] && arr[m] < arr[m - 1])
            r = m - 1;
        else
            l = m + 1;

    }
    return -1;
}


int main(int argc, char** argv)
{
    vector<int> arr = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
    cout << SearchBotinicArrayMax(arr) << endl;
    arr = {1, 3, 50, 10, 9, 7, 6};
    cout << SearchBotinicArrayMax(arr) << endl;
    arr = {120, 100, 80, 20, 0};
    cout << SearchBotinicArrayMax(arr) << endl;
}
