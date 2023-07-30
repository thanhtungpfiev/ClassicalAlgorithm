/*
 * File: main.cpp
 * Project: 104. Maximum Depth of Binary Tree
 * File Created: Monday, 24th July 2023 9:44:26 pm
 * Author: Dao Thanh Tung (MS/EDA101-XC) (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);
        if (lDepth > rDepth)
        {
            return lDepth + 1;
        }
        else
        {
            return rDepth + 1;
        }
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct DFSNode
{
    TreeNode *tn;
    int d;
};

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        int result = 0;
        if (root)
        {
            DFSNode DFSNodeRoot;
            DFSNodeRoot.tn = root;
            DFSNodeRoot.d = 1;
            stack<DFSNode> st;
            st.push(DFSNodeRoot);
            while (!st.empty())
            {
                DFSNode u = st.top();
                st.pop();
                if (!u.tn->left && !u.tn->right)
                {
                    if (u.d > result)
                    {
                        result = u.d;
                    }
                }
                if (u.tn->left)
                {
                    DFSNode DFSNodeLeft;
                    DFSNodeLeft.d = u.d + 1;
                    DFSNodeLeft.tn = u.tn->left;
                    st.push(DFSNodeLeft);
                }
                if (u.tn->right)
                {
                    DFSNode DFSNodeRight;
                    DFSNodeRight.d = u.d + 1;
                    DFSNodeRight.tn = u.tn->right;
                    st.push(DFSNodeRight);
                }
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}
