/**********************************************************************
 *
 * author tung.dao tung.dao@lge.com
 *
 * date 9/28/2021
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root) {
            dfs(root, 0, targetSum);
        }
        return ans;
    }
    void dfs(TreeNode* root, int curSum, int tar) {
        temp.push_back(root->val);
        curSum += root->val;
        if (!root->left && !root->right) {
            if (curSum == tar) ans.push_back(temp);


            temp.pop_back();
            return;
        }

        if (root->left) {
            dfs(root->left, curSum, tar);
        }
        if (root->right) {
            dfs(root->right, curSum, tar);
        }

        temp.pop_back();
    }

private:
    vector<vector<int>> ans;
    vector<int> temp;
};

int main()
{
    Solution s;

    TreeNode tn1(7);
    TreeNode tn2(2);
    TreeNode tn3(5);
    TreeNode tn4(1);

    TreeNode tn5(11, &tn1, &tn2);
    TreeNode tn6(13);
    TreeNode tn7(4, &tn3, &tn4);

    TreeNode tn8(4, &tn5, nullptr);
    TreeNode tn9(8, &tn6, &tn7);

    TreeNode tn10(5, &tn8, &tn9);

    vector<vector<int>> ans = s.pathSum(&tn10, 22);

    for (int i = 0; i < ans.size(); ++i) {
        vector<int> temp = ans[i];
        for (int j = 0; j < temp.size(); ++j) {
            cout << temp[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
