/*
 * File: main.cpp
 * Project: ApplyDiscountToPrices
 * File Created: Monday, 6th June 2022 1:47:38 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class Solution
{
public:
    bool isWordPrice(const string &word)
    {
        for (int i = 0; i < word.length(); ++i)
        {
            if (word[0] != '$')
            {
                return false;
            }
            else if (word.length() == 1)
            {
                return false;
            }
            else if (i != 0 && (word[i] < '0' || word[i] > '9'))
            {
                return false;
            }
        }
        return true;
    }
    string convertWord(string &word, int discount)
    {
        string result = "$";
        double price = stod(word.substr(1, word.length() - 1));
        double priceDiscount = price / 100 * discount;
        price -= priceDiscount;
        std::ostringstream streamObj;
        streamObj << std::fixed;
        streamObj << std::setprecision(2);
        streamObj << price;
        result += streamObj.str();
        return result;
    }
    string discountPrices(string sentence, int discount)
    {

        stringstream ss(sentence);
        string word;
        string result;

        while (ss >> word)
        {
            if (isWordPrice(word))
            {
                result += convertWord(word, discount) + " ";
            }
            else
            {
                result += word + " ";
            }
        }
        result.pop_back();
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    string sentence = "there are $1 $2 and 5$ candies in the shop";
    int discount = 50;
    cout << sl.discountPrices(sentence, discount) << endl;
    sentence = "1 2 $3 4 $5 $6 7 8$ $9 $10$";
    discount = 100;
    cout << sl.discountPrices(sentence, discount) << endl;
    return 0;
}