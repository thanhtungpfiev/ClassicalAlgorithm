#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &target)
    {
        long long sum = 0;
        priority_queue<int> pq;
        for (const auto &e : target)
        {
            sum += e;
            pq.push(e);
        }
        while (pq.top() != 1)
        {
            int num = pq.top();
            pq.pop();
            sum -= num;
            if (num <= sum || sum < 1)
                return false;
            int remain = num - sum;
            num %= sum;
            sum += num;
            if (num)
            {
                pq.push(num);
            }
            else
            {
                pq.push(sum);
            }
        }
        return true;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    vector<int> target = {9,3,5};
    cout << sl.isPossible(target) << endl;
    target = {1,1,1,2};
    cout << sl.isPossible(target) << endl;
    target = {8,5};
    cout << sl.isPossible(target) << endl;
    return 0;
}