/*
 * File: main.cpp
 * Project: InsertionSort
 * File Created: Tuesday, 7th June 2022 10:29:00 am
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>

using namespace std;

class InsertionSort
{
private:
    vector<int> &arr;
    bool less(int value1, int value2);
    bool more(int value1, int value2);

public:
    InsertionSort(vector<int> &data);
    virtual void sort();
};

bool InsertionSort::less(int value1, int value2)
{
    return value1 < value2;
}

bool InsertionSort::more(int value1, int value2)
{
    return value1 > value2;
}

InsertionSort::InsertionSort(vector<int> &data)
    : arr(data)
{
}

void InsertionSort::sort()
{
    for (int i = 1; i < arr.size(); ++i) {
        for (int j = i; j > 0; --j) {
            if (more(arr[j - 1], arr[j])) {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
}

int main(int argc, char **argv)
{
    vector<int> data = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    InsertionSort *is = new InsertionSort(data);
    is->sort();
    for (const auto &i : data)
    {
        cout << i << " ";
    }
    cout << endl;
    data = {1, 2, 5, 4, 3};
    InsertionSort *is1 = new InsertionSort(data);
    is1->sort();
    for (const auto &i : data)
    {
        cout << i << " ";
    }

    return 0;
}