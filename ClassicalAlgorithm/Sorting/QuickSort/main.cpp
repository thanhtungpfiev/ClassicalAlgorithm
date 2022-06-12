/*
 * File: main.cpp
 * Project: QuickSort
 * File Created: Sunday, 12th June 2022 4:16:13 pm
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>

using namespace std;

class QuickSort
{
private:
    vector<int> &arr;
    void quickSortUtil(vector<int> &arr, int lower, int upper);

public:
    QuickSort(vector<int> &data);
    virtual void sort();
};

QuickSort::QuickSort(vector<int> &data) : arr(data)
{
}

void QuickSort::sort()
{
    quickSortUtil(arr, 0, arr.size() - 1);
}

void QuickSort::quickSortUtil(vector<int> &arr, int lower, int upper)
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
    swap(arr[upper], arr[start]);         // upper is the pivot position
    quickSortUtil(arr, start, upper - 1); // pivot - 1 is the upper for left sub array
    quickSortUtil(arr, upper + 1, stop);  // pivot + 1 is the lower for right sub array.
}

int main(int argc, char **argv)
{
    std::vector<int> data = {3, 4, 2, 1, 6, 5, 7, 8, 1, 1};
    QuickSort *qs = new QuickSort(data);
    qs->sort();
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << " ";
    }
    return 0;
}