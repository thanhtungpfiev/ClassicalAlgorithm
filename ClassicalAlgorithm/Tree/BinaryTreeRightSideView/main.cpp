/*
 * File: main.cpp
 * Project: BinaryTreeRightSideView
 * File Created: Monday, 11th July 2022 11:26:34 am
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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
    vector<int> rightSideView(TreeNode *root)
    {

        vector<int> ans;
        if (root == nullptr)
            return ans;

        queue<TreeNode *> q;

        q.push(root);    // Initially push the root node
        q.push(nullptr); // Then push nullptr, as level=0 contains only the root node

        TreeNode *curr;

        while (!q.empty())
        {
            if (q.front() != nullptr)
            { // if the end of current level is not reached

                curr = q.front(); // keep the current node

                // push the left and right child of curr node into the queue if exists
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);

                q.pop(); // remove curr node from queue
            }
            else
            { // nullptr signifies the end of the current level, so need to add the last element of this level to ans

                // last element of the level = last deleted element of queue from front
                ans.push_back(curr->val); // curr contains the last deleted element of queue from front

                q.pop(); // remove the nullptr, as this level has been processed

                // if the queue is not empty then again push nullptr to keep a tag at the end of the next level
                if (!q.empty())
                    q.push(nullptr);
            }
        }

        return ans;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    TreeNode *root = new TreeNode(1);
    TreeNode *left1 = new TreeNode(2);
    TreeNode *right1 = new TreeNode(3);
    TreeNode *right2 = new TreeNode(5);
    TreeNode *right3 = new TreeNode(4);

    root->left = left1;
    root->right = right1;
    left1->right = right2;
    right1->right= right3;
    vector<int> ans = sl.rightSideView(root);
    for (const auto &i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}