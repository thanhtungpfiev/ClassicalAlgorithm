/*
 * File: main.cpp
 * Project: SearchSuggestionsSystem
 * File Created: Sunday, 19th June 2022 12:42:34 pm
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        sort(products.begin(), products.end());
        vector<vector<string>> result;
        unordered_map<string, vector<string>> ht;
        for (auto &product : products)
        {
            for (int i = 0; i <= product.length(); ++i)
            {
                if (ht[product.substr(0, i)].size() < 3)
                {
                    ht[product.substr(0, i)].push_back(product);
                }
            }
        }
        for (int i = 1; i <= searchWord.length(); ++i)
        {
            result.push_back(ht[searchWord.substr(0, i)]);
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    vector<string> products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    string searchWord = "mouse";
    products = {"havana"};
    searchWord = "havana";
    products = {"bags", "baggage", "banner", "box", "cloths"};
    searchWord = "bags";
    return 0;
}