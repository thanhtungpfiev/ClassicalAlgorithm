/*
 * File: main.cpp
 * Project: PrefixAndSuffixSearch
 * File Created: Saturday, 18th June 2022 3:15:19 pm
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class WordFilter
{
public:
    unordered_map<string, int> ht;
    WordFilter(vector<string> &words)
    {
        for (int i = 0; i < words.size(); ++i)
        {
            string word = words[i];
            for (int j = 1; j <= word.size(); ++j)
            {
                string prefix = word.substr(0, j);
                for (int k = 0; k < word.size(); ++k)
                {
                    string suffix = word.substr(k, word.size());
                    ht[prefix + "#" + suffix] = i + 1;
                }
            }
        }
    }

    int f(string prefix, string suffix)
    {
        int result = -1;
        string substr = prefix + "#" + suffix;
        result = ht[substr] - 1;
        return result;
    }
};

int main(int argc, char **argv)
{
    vector<string> words = {"apple"};
    WordFilter sl(words);
    cout << sl.f("a", "e") << endl;
    return 0;
}