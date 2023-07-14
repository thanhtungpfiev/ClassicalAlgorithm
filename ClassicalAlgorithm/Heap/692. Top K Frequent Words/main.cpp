/*
 * File: main.cpp
 * Project: TopKFrequentWords
 * File Created: Tuesday, 16th August 2022 10:36:57 am
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
    typedef pair<string, int> mPair;
    struct compareFrequent
    {
        bool operator()(const mPair &p1, const mPair &p2)
        {
            if (p1.second == p2.second)
            {
                return p1.first > p2.first;
            }
            return p1.second < p2.second;
        }
    };

    vector<string> topKFrequent(vector<string> &words, int k)
    {
        map<string, int> ht;
        for (int i = 0; i < words.size(); ++i)
        {
            ht[words[i]]++;
        }
        priority_queue<mPair, vector<mPair>, compareFrequent> pq;
        for (auto it : ht)
        {
            pq.push(make_pair(it.first, it.second));
        }
        vector<string> result;
        while (k > 0)
        {
            result.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: words = ["i","love","leetcode","i","love","coding"], k = 2
    // Output: ["i","love"]
    // Explanation: "i" and "love" are the two most frequent words.
    // Note that "i" comes before "love" due to a lower alphabetical order.

    // Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
    // Output: ["the","is","sunny","day"]
    // Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
    return 0;
}