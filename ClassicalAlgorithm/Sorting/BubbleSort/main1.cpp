/*
 * File: main1.cpp
 * Project: BubbleSort
 * File Created: Monday, 6th June 2022 5:31:25 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>

using namespace std;

class BubbleSort
{
private:
    vector<int> &arr;
    bool less(int value1, int value2);
    bool more(int value1, int value2);

public:
    BubbleSort(vector<int> &data);
    virtual void sort();
    virtual void sort2();
};

bool BubbleSort::less(int value1, int value2)
{
    return value1 < value2;
}

bool BubbleSort::more(int value1, int value2)
{
    return value1 > value2;
}

BubbleSort::BubbleSort(vector<int> &data)
    : arr(data)
{
}

void BubbleSort::sort()
{
    int size = arr.size();
    int i, j, temp;
    for (i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (more(arr[j], arr[j + 1]))
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void BubbleSort::sort2()
{
    int size = arr.size();
    int i, j, temp;
    int swapped = 1;
    for (i = 0; i < size - 1 && swapped == 1; ++i)
    {
        swapped = 0;
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (more(arr[j], arr[j + 1]))
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
    }
}

int main(int argc, char **argv)
{
    vector<int> data = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    BubbleSort *bs = new BubbleSort(data);
    bs->sort();
    for (const auto &i : data)
    {
        cout << i << " ";
    }
    cout << endl;
    data = {1, 2, 5, 4, 3};
    BubbleSort *bs1 = new BubbleSort(data);
    bs1->sort2();
    for (const auto &i : data)
    {
        cout << i << " ";
    }

    return 0;
}