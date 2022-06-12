/*
 * File: main.cpp
 * Project: QuickSelect
 * File Created: Sunday, 12th June 2022 4:32:43 pm
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>

using namespace std;

class QuickSelect
{
private:
    static void quickSelect(vector<int> &arr, int lower, int upper, int k);

public:
    static void quickSelect(vector<int> &arr, int k);
};

void QuickSelect::quickSelect(vector<int> &arr, int lower, int upper, int k)
{
    if (upper <= lower)
    {
        return;
    }
    int pivot = arr[lower];
    int start = lower;
    int stop = upper;

    while (lower < upper)
    {
        while (arr[lower] <= pivot && lower < upper)
        {
            lower++;
        }
        while (arr[upper] > pivot && lower <= upper)
        {
            upper--;
        }
        if (lower < upper)
        {
            swap(arr[upper], arr[lower]);
        }
    }
    swap(arr[start], arr[upper]);
    if (k < upper)
    {
        quickSelect(arr, start, upper - 1, k);
    }
    if (k > upper)
    {
        quickSelect(arr, upper + 1, stop, k);
    }
}

void QuickSelect::quickSelect(vector<int> &arr, int k)
{
    quickSelect(arr, 0, arr.size() - 1, k);
}

int main(int argc, char **argv)
{
    std::vector<int> data = {3, 4, 2, 1, 6, 5, 7, 8, 10, 9};
    QuickSelect::quickSelect(data, 5);
    std::cout << "value at index 5 is : " << data[4];
    return 0;
}