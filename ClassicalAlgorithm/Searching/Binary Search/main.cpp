/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 5/30/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
 ***********************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binarySearch(vector<int> &data, int value)
{
    int size = data.size();
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (data[mid] == value)
        {
            return true;
        }
        else if (data[mid] < value)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return false;
}

bool binarySearchRecursive(vector<int> &data, int low, int high, int value)
{
    if (low > high)
    {
        return false;
    }
    int mid = low + (high - low) / 2;
    if (data[mid] == value)
    {
        return true;
    }
    else if (data[mid] < value)
    {
        return binarySearchRecursive(data, mid + 1, high, value);
    }
    else
    {
        return binarySearchRecursive(data, low, mid - 1, value);
    }
}

int findIndex(vector<int> &data, int value)
{
    auto it = lower_bound(data.begin(), data.end(), value);
    if (it != data.end() && *it == value)
    {
        return it - data.begin();
    }
    return -1;
}

int main()
{
    vector<int> v = {10, 20, 30, 50, 60, 80, 110, 130, 140, 170};
    cout << binarySearch(v, 110) << endl;
    cout << binarySearch(v, 175) << endl;

    cout << binarySearchRecursive(v, 0, v.size() - 1, 110) << endl;
    cout << binarySearchRecursive(v, 0, v.size() - 1, 175) << endl;

    cout << binary_search(v.begin(), v.end(), 110) << endl;
    cout << binary_search(v.begin(), v.end(), 175) << endl;
    return 0;
}
