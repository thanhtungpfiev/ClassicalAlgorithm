/*
 * File: main.cpp
 * Project: ConstructBinaryTreeFromInorderAndPostorderTraversal
 * File Created: Thursday, 14th July 2022 10:29:41 am
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>

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
    int postorderIndex;
    unordered_map<int, int> inorderIndexMap;
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        postorderIndex = postorder.size() - 1;
        // build a hashmap to store value -> its index relations
        for (int i = 0; i < inorder.size(); ++i)
        {
            inorderIndexMap[inorder[i]] = i;
        }
        return arrayToTree(postorder, 0, postorder.size() - 1);
    }

    TreeNode *arrayToTree(vector<int> &postorder, int left, int right)
    {
        // if there are no elements to construct the tree
        if (left > right)
            return nullptr;

        // select the preorder_index element as the root and increment it
        int rootValue = postorder[postorderIndex--];
        TreeNode *root = new TreeNode(rootValue);
        // build left and right subtree
        // excluding inorderIndexMap[rootValue] element because it's the root
        root->right = arrayToTree(postorder, inorderIndexMap[rootValue] + 1, right);
        root->left = arrayToTree(postorder, left, inorderIndexMap[rootValue] - 1);
        return root;
    }
};

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    // Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
    // Output: [3,9,20,null,null,15,7]
    // Input: inorder = [-1], postorder = [-1]
    // Output: [-1]
    return 0;
}