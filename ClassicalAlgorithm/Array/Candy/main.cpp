/*
 * File: main.cpp
 * Project: Candy
 * File Created: Monday, 4th July 2022 11:41:38 am
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> left2right(n, 1);
        vector<int> right2left(n, 1);
        for (int i = 1; i < n; ++i)
        {
            if (ratings[i] > ratings[i - 1])
            {
                left2right[i] = left2right[i - 1] + 1;
            }
        }
        for (int i = n - 1; i > 0; --i)
        {
            if (ratings[i - 1] > ratings[i])
            {
                right2left[i - 1] = right2left[i] + 1;
            }
        }
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += max(left2right[i], right2left[i]);
        }
        return sum;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: ratings = [1,0,2]
    // Output: 5
    // Input: ratings = [1,2,2]
    // Output: 4
    vector<int> ratings = {1, 0, 2};
    cout << sl.candy(ratings) << endl;
    ratings = {1, 2, 2};
    cout << sl.candy(ratings) << endl;
    return 0;
}