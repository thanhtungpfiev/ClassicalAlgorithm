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
    TreeNode *tn;
    int d;
};
class Solution {
public:
    int maxDepth(TreeNode* root) {
       int maxD = 0;
        if (root) {
         DFSNode DFSNodeRoot;
            DFSNodeRoot.tn = root;
            DFSNodeRoot.d = 1;
            stack<DFSNode> st;
            st.push(DFSNodeRoot);
            while (!st.empty()) {
                DFSNode node = st.top();
                st.pop();
                if (!node.tn->left && !node.tn->right) {
                    if (node.d > maxD) {
                        maxD = node.d;
                    }
                }
                if (node.tn->left) {
                    DFSNode DFSNodeLeft;
                    DFSNodeLeft.tn = node.tn->left;
                    DFSNodeLeft.d = node.d + 1;
                    st.push(DFSNodeLeft);
                }
                if (node.tn->right) {
                    DFSNode DFSNodeRight;
                    DFSNodeRight.tn = node.tn->right;
                    DFSNodeRight.d = node.d + 1;
                    st.push(DFSNodeRight);
                }
            }
        }
        return maxD;
    }
};

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
