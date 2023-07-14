/*
 * File: main.cpp
 * Project: DeleteOperationForTwoStrings
 * File Created: Tuesday, 14th June 2022 2:51:36 pm
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> F(n + 1, vector<int>(m + 1));
        for (int i = 0; i <= n; ++i)
            F[i][0] = i;
        for (int j = 0; j <= m; ++j)
            F[0][j] = j;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    F[i][j] = F[i - 1][j - 1];
                }
                else
                {
                    F[i][j] = min(F[i][j - 1], F[i - 1][j]) + 1;
                }
            }
        }

        int i = n, j = m;
        while ((i >= 0) && (j >= 0))
        {
            if (word1[i - 1] == word2[j - 1])
            { // Hai ký tự cuối của xâu giống nhau
                --i;
                --j;
            }
            else
            {
                if (F[i][j] == F[i][j - 1] + 1)
                { // Phép xóa word2
                    cout << "Delete(" << i << "," << word2[j - 1] << ")" << endl;
                    --j;
                }
                else
                { // Phép xóa word1
                    cout << "Delete(" << i << "," << word1[i - 1] << ")" << endl;
                    --i;
                }
            }
        }

        return F[n][m];
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    string word1 = "sea", word2 = "eat";
    cout << sl.minDistance(word1, word2) << endl;

    word1 = "leetcode", word2 = "etco";
    cout << sl.minDistance(word1, word2) << endl;
    return 0;
}