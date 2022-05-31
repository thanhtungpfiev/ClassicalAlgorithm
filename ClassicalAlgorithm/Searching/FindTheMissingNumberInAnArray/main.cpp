/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 5/31/2022
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

int findMissingNumber(vector<int> &data)
{
    int found;
    for (int i = 1; i <= data.size(); ++i) {
        found = 0;
        for (int j = 0; j < data.size(); ++j) {
            if (data[j] == i) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            return i;
        }
    }
    return 0;
}

int findMissingNumber2(vector<int> &data)
{
    unordered_map<int, int> ht;
    for (int i = 0; i < data.size(); ++i) {
        ht[data[i]]++;
    }
    for (int i = 1; i <= data.size(); ++i) {
        if (ht[i] == 0) {
            return i;
        }
    }
    return 0;
}

int findMissingNumber3(vector<int> &data)
{
    int sum = data.size() * (data.size() - 1) / 2;
    int result = 0;
    for (int i = 0; i < data.size(); ++i) {
        result = sum - data[i];
    }
    return result;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
