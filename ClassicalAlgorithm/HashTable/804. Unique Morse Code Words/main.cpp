/*
 * File: main.cpp
 * Project: UniqueMorseCodeWords
 * File Created: Wednesday, 17th August 2022 10:20:47 am
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
    int uniqueMorseRepresentations(vector<string> &words)
    {
        vector<string> v = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string> ht;
        for (auto word : words)
        {
            string temp;
            for (auto c : word)
            {
                temp += v[c - 'a'];
            }
            ht.insert(temp);
        }
        return ht.size();
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: words = ["gin","zen","gig","msg"]
    // Output: 2
    // Explanation: The transformation of each word is:
    // "gin" -> "--...-."
    // "zen" -> "--...-."
    // "gig" -> "--...--."
    // "msg" -> "--...--."
    // There are 2 different transformations: "--...-." and "--...--.".

    // Input: words = ["a"]
    // Output: 1
    return 0;
}