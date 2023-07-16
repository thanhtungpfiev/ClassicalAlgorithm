#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        double result = 0.0;
        double sum = 0.0;
        double temp = 0.0;
        for (int i = 0; i < k; ++i)
        {
            sum += nums[i];
        }
        temp = sum;
        for (int i = k; i < nums.size(); ++i)
        {
            temp += nums[i] - nums[i - k];
            if (temp > sum)
            {
                sum = temp;
            }
        }
        result = sum * 1.0 / k;
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}