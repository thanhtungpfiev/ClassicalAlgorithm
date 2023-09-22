/*
 * File: main.cpp
 * Project: 450. Delete Node in a BST
 * File Created: Thursday, 21st September 2023 1:49:08 pm
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
    int FindMax(TreeNode *root)
    {
        if (root == nullptr) {
            return -1;
        }
        while (root->right != nullptr) {
            root = root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }
        TreeNode* temp = nullptr;
        if (root->val == key) {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            } else {
                if (root->left == nullptr) {
                    temp = root->right;
                    delete root;
                    return temp;
                }
                if (root->right == nullptr) {
                    temp = root->left;
                    delete root;
                    return temp;
                }
                int maxVal = FindMax(root->left);
                root->val = maxVal;
                root->left = deleteNode(root->left, maxVal);
            }
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}