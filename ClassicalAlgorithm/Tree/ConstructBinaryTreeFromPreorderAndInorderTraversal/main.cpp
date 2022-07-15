/*
 * File: main.cpp
 * Project: ConstructBinaryTreeFromPreorderAndInorderTraversal
 * File Created: Thursday, 14th July 2022 10:09:50 am
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
    int preorderIndex;
    unordered_map<int, int> inorderIndexMap;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        preorderIndex = 0;
        // build a hashmap to store value -> its index relations
        for (int i = 0; i < inorder.size(); ++i)
        {
            inorderIndexMap[inorder[i]] = i;
        }
        return arrayToTree(preorder, 0, preorder.size() - 1);
    }
    TreeNode *arrayToTree(vector<int> &preorder, int left, int right)
    {
        // if there are no elements to construct the tree
        if (left > right)
            return nullptr;

        // select the preorder_index element as the root and increment it
        int rootValue = preorder[preorderIndex++];
        TreeNode *root = new TreeNode(rootValue);
        // build left and right subtree
        // excluding inorderIndexMap[rootValue] element because it's the root
        root->left = arrayToTree(preorder, left, inorderIndexMap[rootValue] - 1);
        root->right = arrayToTree(preorder, inorderIndexMap[rootValue] + 1, right);
        return root;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    // Output: [3,9,20,null,null,15,7]
    // Input: preorder = [-1], inorder = [-1]
    // Output: [-1]
    return 0;
}