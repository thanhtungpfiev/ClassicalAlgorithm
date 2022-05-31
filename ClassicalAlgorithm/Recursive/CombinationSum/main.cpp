/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 5/31/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    void generate(const vector<int> &candidates, int target, vector<int> &candidate, int currSum, int currIndex) {
        if (currSum == target) {
            result.push_back(candidate);
            return;
        }
        if (currSum > target) {
            return;
        }
        for (int i = currIndex; i < candidates.size(); ++i) {
            candidate.push_back(candidates[i]);
            currSum += candidates[i];
            generate(candidates, target, candidate, currSum, i);
            candidate.pop_back();
            currSum -= candidates[i];
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> candidate;
        generate(candidates, target, candidate, 0, 0);
        return result;
    }
};

int main()
{
    Solution sl;
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> result = sl.combinationSum(candidates, target);
    candidates = {2,3,5};
    target = 8;
    result = sl.combinationSum(candidates, target);
    candidates = {2};
    target = 1;
    result = sl.combinationSum(candidates, target);

    return 0;
}
