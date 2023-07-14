/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 5/10/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

long long int coinChange(vector<int>& S, int m, int n, vector<vector<int>>& dp)
{
    if (n == 0) {
        return 1;
    }
    if (m == 0) {
        return 0;
    }
    if (dp[m][n] != -1) return dp[m][n];
    if (S[m - 1] <= n) {
        return coinChange(S, m - 1, n, dp) + coinChange(S, m, n - S[m - 1], dp);
    } else {
        return coinChange(S, m - 1, n, dp);
    }
}

long long int count(vector<int>& S, int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    long long int res = coinChange(S, m, n, dp);
    return res;
}

long long int count(int S[], int m, int n )
{
    // table[i] will be storing the number of solutions for
    // value i. We need n+1 rows as the table is constructed
    // in bottom up manner using the base case (n = 0)
    long long int table[n+1];
    // Initialize all table values as 0
    memset(table, 0, sizeof(table));
    // Base case (If given value is 0)
    table[0] = 1;
    // Pick all coins one by one and update the table[] values
    // after the index greater than or equal to the value of the
    // picked coin
    for(int i=0; i<m; i++)
        for(int j=S[i]; j<=n; j++)
            table[j] += table[j-S[i]];
    return table[n];
}

int main()
{
    int m = 3, n = 4;
    vector<int> a = { 1, 2, 3 };
    long long int res = count(a, m, n);
    cout << res << endl;
    return 0;
}
