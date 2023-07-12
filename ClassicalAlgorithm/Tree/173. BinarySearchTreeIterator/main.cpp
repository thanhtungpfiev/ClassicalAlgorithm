/*
 * File: main.cpp
 * Project: BinarySearchTreeIterator
 * File Created: Friday, 26th August 2022 9:43:43 am
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
class BSTIterator
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    queue<TreeNode *> q;
    BSTIterator(TreeNode *root)
    {
        q.push(root);
        while (!q.empty())
        {
            TreeNode *tn = q.front();
            q.pop();
            pq.push(tn->val);
            if (tn->left)
                q.push(tn->left);
            if (tn->right)
                q.push(tn->right);
        }
    }

    int next()
    {
        int val = pq.top();
        pq.pop();
        return val;
    }

    bool hasNext()
    {
        return !pq.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

class BSTIterator
{
    stack<TreeNode *> myStack;

public:
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node)
    {
        for (; node != NULL; myStack.push(node), node = node->left)
            ;
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input
    // ["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
    // [[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
    // Output
    // [null, 3, 7, true, 9, true, 15, true, 20, false]

    // Explanation
    // BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
    // bSTIterator.next();    // return 3
    // bSTIterator.next();    // return 7
    // bSTIterator.hasNext(); // return True
    // bSTIterator.next();    // return 9
    // bSTIterator.hasNext(); // return True
    // bSTIterator.next();    // return 15
    // bSTIterator.hasNext(); // return True
    // bSTIterator.next();    // return 20
    // bSTIterator.hasNext(); // return False
    return 0;
}