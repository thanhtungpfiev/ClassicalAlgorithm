/*
 * File: main.cpp
 * Project: MoveNegativeAndPositiveNumbers
 * File Created: Saturday, 4th June 2022 7:27:37 pm
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void move(vector<int> &data)
{
    sort(data.begin(), data.end());
}

void move2(vector<int> &data)
{
    int l = 0, r = data.size() - 1;
    while (l < r) {
        if (data[l] < 0) {
            l++;
        } else if (data[r] > 0) {
            r--;
        } else {
            swap(data[l], data[r]);
            l++;
            r--;
        }
    }
}

void print(const vector<int> &data)
{
    for (const auto &i : data) {
        cout << i << " ";
    }
    cout << endl;
}


int main(int argc, char **argv)
{
    vector<int> data = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    // move(data);
    // print(data);
    move2(data);
    print(data);
    return 0;
}