/**********************************************************************
 *
 * author tung.dao tung.dao@lge.com
 *
 * date 9/29/2021
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
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
    TreeNode *tn;
};

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        if (root) {
            DFSNode DFSNodeRoot;
            DFSNodeRoot.val = root->val;
            DFSNodeRoot.tn = root;
            stack<DFSNode> st;
            st.push(DFSNodeRoot);
            while (!st.empty()) {
                DFSNode node = st.top();
                st.pop();

                if (node.tn->val >= node.val) {
                    cnt++;
                }
                if (node.tn->left) {
                    DFSNode DFSNodeLeft;
                    DFSNodeLeft.tn = node.tn->left;
                    if (node.tn->val >= node.val) {
                        DFSNodeLeft.val = node.tn->val;
                    } else {
                        DFSNodeLeft.val = node.val;
                    }
                    st.push(DFSNodeLeft);
                }
                if (node.tn->right) {
                    DFSNode DFSNodeRight;
                    DFSNodeRight.tn = node.tn->right;
                    if (node.tn->val >= node.val) {
                        DFSNodeRight.val = node.tn->val;

                    } else {
                        DFSNodeRight.val = node.val;
                    }
                    st.push(DFSNodeRight);
                }
            }
        }
        return cnt;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
