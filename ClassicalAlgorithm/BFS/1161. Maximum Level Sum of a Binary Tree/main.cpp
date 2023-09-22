/*
 * File: main.cpp
 * Project: 1161. Maximum Level Sum of a Binary Tree
 * File Created: Tuesday, 19th September 2023 4:51:59 pm
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
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int result = 0;
        int sum_m = INT_MIN;
        int result_m = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sum = 0;
            int currentNodeAtEachLevel = q.size();
            result_m++;
            while (currentNodeAtEachLevel > 0) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
                currentNodeAtEachLevel--;
            }
            if (sum > sum_m) {
                sum_m = sum;
                result = result_m;
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