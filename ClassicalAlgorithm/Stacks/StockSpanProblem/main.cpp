#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class StockSpanner
{
public:
    vector<int> m_stock;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int result = 0;
        m_stock.push_back(price);
        for (int i = m_stock.size() - 1; i >= 0; --i)
        {
            if (price < m_stock[i])
            {
                break;
            }
            ++result;
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}