#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        vector<int> sumFromBegining(n + 1);
        vector<int> sumFromEnd(n + 1);
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += cardPoints[i];
            sumFromBegining[i + 1] = sum;
        }
        sum = 0;
        for (int i = n - 1, j = 0; i >= 0; --i, ++j)
        {
            sum += cardPoints[i];
            sumFromEnd[j + 1] = sum;
        }
        int result = 0;
        for (int i = 0; i <= k; ++i)
        {
            result = max(result, sumFromBegining[i] + sumFromEnd[k - i]);
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    cout << sl.maxScore(cardPoints, k) << endl;
    cardPoints = {2, 2, 2};
    k = 2;
    cout << sl.maxScore(cardPoints, k) << endl;
    cardPoints = {9, 7, 7, 9, 7, 7, 9};
    k = 7;
    cout << sl.maxScore(cardPoints, k) << endl;
    return 0;
}