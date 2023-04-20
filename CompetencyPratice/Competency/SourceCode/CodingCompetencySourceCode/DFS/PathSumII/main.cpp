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
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct DFSNode {
    int val;
    vector<int> path;
    TreeNode *tn;
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root) {
            stack<DFSNode> st;
            DFSNode DFSRoot;
            DFSRoot.val = root->val;
            DFSRoot.path.push_back(root->val);
            DFSRoot.tn = root;
            st.push(DFSRoot);
            while (!st.empty()) {
                DFSNode node = st.top();
                st.pop();
                if (!node.tn->left && !node.tn->right) {
                    if (node.val == targetSum) {
                        ans.push_back(node.path);
                    }
                }
                if (node.tn->left) {
                    DFSNode nextNodeLeft;
                    nextNodeLeft.val = node.val + node.tn->left->val;
                    nextNodeLeft.path = node.path;
                    nextNodeLeft.path.push_back(node.tn->left->val);
                    nextNodeLeft.tn = node.tn->left;
                    st.push(nextNodeLeft);
                }
                if (node.tn->right) {
                    DFSNode nextNodeRight;
                    nextNodeRight.val = node.val + node.tn->right->val;
                    nextNodeRight.path = node.path;
                    nextNodeRight.path.push_back(node.tn->right->val);
                    nextNodeRight.tn = node.tn->right;
                    st.push(nextNodeRight);
                }
            }
        }
        return ans;
    }

private:
    vector<vector<int>> ans;
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
