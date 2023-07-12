/*
 * File: main.cpp
 * Project: ConvertSortedArrayToBinarySearchTree
 * File Created: Wednesday, 10th August 2022 10:29:49 am
 * Author: tung.dao (thanhtungpfiev@gmail.com)
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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
    TreeNode *sortedArrayToBST(vector<int> &nums, int start, int end)
    {
        TreeNode *root = nullptr;
        if (start > end)
        {
            return root;
        }
        int mid = start + (end - start) / 2;
        root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, start, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, end);
        return root;
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: nums = [-10,-3,0,5,9]
    // Output: [0,-3,9,-10,null,5]
    // Explanation: [0,-10,5,null,-3,null,9] is also accepted:

    // Input: nums = [1,3]
    // Output: [3,1]
    // Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
    return 0;
}