/*
 * File: main.cpp
 * Project: StockPurchaseSellProblem
 * File Created: Thursday, 2nd June 2022 3:14:38 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>

void maxProfit(std::vector<int> &stocks)
{
    int buy = 0, sell = 0;
    int curMin = 0;
    int curProfit = 0;
    int maxProfit = 0;
    for (int i = 0; i < stocks.size(); i++)
    {
        if (stocks[i] < stocks[curMin])
        {
            curMin = i;
        }
        curProfit = stocks[i] - stocks[curMin];
        if (curProfit > maxProfit)
        {
            buy = curMin;
            sell = i;
            maxProfit = curProfit;
        }
    }
    cout << "Purchase day is" << buy << " at price " << stocks[buy] << endl;
    cout << "Sell day is" << sell << " at price " << stocks[sell] << endl;
}

using namespace std;

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}