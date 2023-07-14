/*
 * File: main.cpp
 * Project: MergeSort
 * File Created: Tuesday, 7th June 2022 11:21:12 am
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>

using namespace std;

class MergeSort
{
private:
    std::vector<int> &arr;
    void merge(std::vector<int> &arr, std::vector<int> &tempArray, int lowerIndex, int middleIndex, int upperIndex);
    void mergeSrt(std::vector<int> &arr, std::vector<int> &tempArray, int lowerIndex, int upperIndex);

public:
    MergeSort(std::vector<int> &data);
    virtual void sort();
};

MergeSort::MergeSort(std::vector<int> &data)
    : arr(data)
{
}
void MergeSort::sort()
{
    int size = arr.size();
    std::vector<int> tempArray(size);
    mergeSrt(arr, tempArray, 0, size - 1);
}
void MergeSort::mergeSrt(std::vector<int> &arr, std::vector<int> &tempArray, int lowerIndex, int upperIndex)
{
    if (lowerIndex >= upperIndex)
    {
        return;
    }
    int middleIndex = lowerIndex + (upperIndex - lowerIndex) / 2;
    mergeSrt(arr, tempArray, lowerIndex, middleIndex);
    mergeSrt(arr, tempArray, middleIndex + 1, upperIndex);
    merge(arr, tempArray, lowerIndex, middleIndex, upperIndex);
}

void MergeSort::merge(std::vector<int> &arr, std::vector<int> &tempArray, int lowerIndex, int middleIndex, int upperIndex)
{
    int lowerStart = lowerIndex;
    int lowerStop = middleIndex;
    int upperStart = middleIndex + 1;
    int upperStop = upperIndex;
    int count = lowerIndex;
    while (lowerStart <= lowerStop && upperStart <= upperStop) {
        if (arr[lowerStart] < arr[upperStart]) {
            tempArray[count++] = arr[lowerStart++];
        } else {
            tempArray[count++] = arr[upperStart++];
        }
    }
    while (lowerStart <= lowerStop) {
        tempArray[count++] = arr[lowerStart++];
    }
    while (upperStart <= upperStop) {
        tempArray[count++] = arr[upperStart++];
    }
    for (int i = lowerIndex; i <= upperIndex; i++) {
        arr[i] = tempArray[i];
    }
}

int main(int argc, char **argv)
{
    vector<int> data = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    MergeSort *ms = new MergeSort(data);
    ms->sort();
    for (const auto &i : data)
    {
        cout << i << " ";
    }
    cout << endl;
    data = {1, 2, 5, 4, 3};
    MergeSort *ms1 = new MergeSort(data);
    ms1->sort();
    for (const auto &i : data)
    {
        cout << i << " ";
    }

    return 0;
}