/*
 * File: main.cpp
 * Project: KthSmallestElementInABST
 * File Created: Thursday, 25th August 2022 10:22:57 am
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
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
    int kthSmallest(TreeNode *root, int k)
    {
        priority_queue<int> pq;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *tn = q.front();
            q.pop();
            if (pq.size() < k)
            {
                pq.push(tn->val);
            }
            else
            {
                if (tn->val < pq.top())
                {
                    pq.pop();
                    pq.push(tn->val);
                }
            }
            if (tn->left)
                q.push(tn->left);
            if (tn->right)
                q.push(tn->right);
        }
        return pq.top();
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: root = [3,1,4,null,2], k = 1
    // Output: 1

    // Input: root = [5,3,6,2,4,null,null,1], k = 3
    // Output: 3
    return 0;
}