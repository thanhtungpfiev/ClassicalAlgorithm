#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int countHousePlacements(int n)
    {
        using ll = long long;
        ll mod = 1e9 + 7;
        ll house = 1, space = 1;
        ll total = house + space;
        for (int i = 1; i < n; ++i)
        {
            house = space;
            space = total;
            total = (house + space) % mod;
        }
        return (total * total) % mod;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    int n = 1;
    cout << sl.countHousePlacements(n) << endl;
    n = 2;
    cout << sl.countHousePlacements(n) << endl;
    return 0;
}