/*
 * File: main.cpp
 * Project: BucketSort
 * File Created: Sunday, 12th June 2022 4:44:42 pm
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>

using namespace std;

class BucketSort
{
private:
    vector<int> &data;
    int range = 0;
    int lowerRange = 0;

public:
    BucketSort(vector<int> &arr, int lowerRange, int upperRange);
    virtual void sort();
};

BucketSort::BucketSort(vector<int> &arr, int lowerRange, int upperRange) : data(arr)
{
    range = upperRange - lowerRange;
    this->lowerRange = lowerRange;
}

void BucketSort::sort()
{
    vector<int> count(range);
    for (int i = 0; i < data.size(); i++)
    {
        count[data[i] - lowerRange]++;
    }
    int j = 0;
    for (int i = 0; i < range; i++)
    {
        for (; count[i] > 0; count[i]--)
        {
            data[j++] = i + lowerRange;
        }
    }
}

int main(int argc, char **argv)
{
    std::vector<int> data = {23, 24, 22, 21, 26, 25, 27, 28, 21, 21};
    BucketSort *m = new BucketSort(data, 20, 30);
    m->sort();
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << " ";
    }
    return 0;
}