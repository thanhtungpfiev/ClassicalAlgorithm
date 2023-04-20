/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 7/30/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int>& v, int lo, int hi) {
    int pivot = v[lo];
    int left = lo + 1;
    int right = hi;
    while (true) {
        while (v[left] < pivot && left <= right) left++;
        while (v[right] > pivot && left <= right) right--;
        if (left < right) {
            swap(v[left], v[right]);
            left++;
            right--;
        } else {
            break;
        }
    }
    swap(v[lo], v[right]);
    return right;
}

int partition2(vector<int>& v, int lo, int hi) {
    int pivot = v[hi];
    int left = lo;
    int right = hi - 1;
    while (true) {
        while (v[left] < pivot && left <= right) left++;
        while (v[right] > pivot && left <= right) right--;
        if (left < right) {
            swap(v[left], v[right]);
            left++;
            right--;
        } else {
            break;
        }
    }
    swap(v[left], v[hi]);
    return left;
}

void quickSort(vector<int>& v, int lo, int hi) {
    if (lo < hi) {
        int p = partition(v, lo, hi);
        quickSort(v, lo, p - 1);
        quickSort(v, p + 1, hi);
    }
}

void quickSort2(vector<int>& v, int lo, int hi) {
    if (lo < hi) {
        int p = partition2(v, lo, hi);
        quickSort2(v, lo, p - 1);
        quickSort2(v, p + 1, hi);
    }
}

vector<int> fillVector(int size) {
    vector<int> v;
    for (int i = 0; i < size; ++i) {
        v.push_back(rand() % size);
    }
    return v;
}

void printVector(const vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Hello World!" << endl;
    vector<int> v = {1, 3, 2, 5, 4};
    quickSort2(v, 0, v.size() - 1);
    printVector(v);

    vector<int> v1 = fillVector(100);
    quickSort(v1, 0, v1.size() - 1);
    printVector(v1);

    vector<int> v2 = {1, 3, 2, 5, 4, 7, 1 , 5};
    quickSort2(v2, 0, v2.size() - 1);
    printVector(v2);
    return 0;
}
