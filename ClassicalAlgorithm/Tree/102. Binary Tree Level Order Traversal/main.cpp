/*
 * File: main.cpp
 * Project: BinaryTreeLevelOrderTraversal
 * File Created: Wednesday, 13th July 2022 11:27:17 am
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    struct BFSNode
    {
        TreeNode *curr;
        int level;
        BFSNode(TreeNode *tn, int lv)
        {
            curr = tn;
            level = lv;
        }
    };
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        vector<vector<int>> result;
        queue<BFSNode *> q;
        q.push(new BFSNode(root, 0));
        map<int, vector<int>> ht;
        while (!q.empty())
        {
            BFSNode *node = q.front();
            q.pop();
            ht[node->level].push_back(node->curr->val);
            if (node->curr->left != nullptr)
                q.push(new BFSNode(node->curr->left, node->level + 1));
            if (node->curr->right != nullptr)
                q.push(new BFSNode(node->curr->right, node->level + 1));
        }
        for (auto it : ht)
        {
            result.push_back(it.second);
        }
        return result;
    }
};

class Solution1
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        queue<TreeNode *> q;
        q.push(root);
        q.push(nullptr);
        vector<vector<int>> result;
        vector<int> temp;
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node != nullptr)
            {
                temp.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            else
            {
                result.push_back(temp);
                temp.clear();
                if (!q.empty())
                {
                    q.push(nullptr);
                }
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: root = [3,9,20,null,null,15,7]
    // Output: [[3],[9,20],[15,7]]
    // Input: root = [1]
    // Output: [[1]]
    // Input: root = []
    // Output: []
    return 0;
}