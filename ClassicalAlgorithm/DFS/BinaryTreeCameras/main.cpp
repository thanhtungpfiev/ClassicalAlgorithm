/*
 * File: main.cpp
 * Project: BinaryTreeCameras
 * File Created: Friday, 17th June 2022 10:08:46 am
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
    int minCameraCover(TreeNode *root)
    {
        vector<int> ans = solve(root);
        return min(ans[1], ans[2]);
    }

    vector<int> solve(TreeNode *node)
    {
        if (node == nullptr)
        {
            return {0, 0, 99999};
        }
        vector<int> L = solve(node->left);
        vector<int> R = solve(node->right);
        int mL12 = min(L[1], L[2]);
        int mR12 = min(R[1], R[2]);
        int d0 = L[1] + R[1];
        int d1 = min(L[2] + mR12, R[2] + mL12);
        int d2 = 1 + min(L[0], mL12) + min(R[0], mR12);
        return {d0, d1, d2};
    }
};

class Solution2
{
public:
    int camera = 0;
    enum Camera
    {
        HAS_CAMERA,
        COVERED,
        PLEASE_COVER
    };

    int minCameraCover(TreeNode *root)
    {
        // If root is not covered then we need to place a camera at root node
        return cover(root) == Camera::PLEASE_COVER ? ++camera : camera;
    }

    Camera cover(TreeNode *node)
    {

        // Base case - if there is no node then it's already covered
        if (node == nullptr)
            return Camera::COVERED;

        // Try to cover left and right children's subtree
        Camera l = cover(node->left);
        Camera r = cover(node->right);

        // If Any one of the children is not covered then we must place a camera at current node
        if (l == Camera::PLEASE_COVER || r == Camera::PLEASE_COVER)
        {
            camera++;
            return Camera::HAS_CAMERA;
        }

        // If any one of left or right node has Camera then the current node is also covered
        if (l == Camera::HAS_CAMERA || r == Camera::HAS_CAMERA)
            return Camera::COVERED;

        // If None of the children is covering the current node then ask it's parent to cover
        return Camera::PLEASE_COVER;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}