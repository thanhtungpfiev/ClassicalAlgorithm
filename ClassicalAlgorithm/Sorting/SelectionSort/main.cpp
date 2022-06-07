/*
 * File: main.cpp
 * Project: SelectionSort
 * File Created: Tuesday, 7th June 2022 11:06:51 am
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>

using namespace std;

class SelectionSort
{
private:
    std::vector<int> &arr;
    bool less(int value1, int value2);
    bool more(int value1, int value2);

public:
    SelectionSort(std::vector<int> &data);
    virtual void sort();  // back array
    virtual void sort2(); // front array
};
SelectionSort::SelectionSort(std::vector<int> &data)
    : arr(data)
{
}
bool SelectionSort::less(int value1, int value2)
{
    return value1 < value2;
}
bool SelectionSort::more(int value1, int value2)
{
    return value1 > value2;
}
void SelectionSort::sort()
{
    for (int i = 0; i < arr.size(); ++i)
    {
        int max = 0;
        for (int j = 1; j < arr.size() - i; ++j)
        {
            if (arr[j] > arr[max])
            {
                max = j;
            }
        }
        swap(arr[arr.size() - i - 1], arr[max]);
    }
}

void SelectionSort::sort2()
{
    int size = arr.size();
    int i, j, min, temp;
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}