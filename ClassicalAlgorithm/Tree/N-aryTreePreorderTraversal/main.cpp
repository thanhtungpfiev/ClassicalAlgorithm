/*
 * File: main.cpp
 * Project: N-aryTreePreorderTraversal
 * File Created: Tuesday, 26th July 2022 11:16:11 am
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> result;
        stack<Node *> st;
        st.push(root);
        while (!st.empty())
        {
            Node *node = st.top();
            st.pop();
            if (node != nullptr)
            {
                result.push_back(node->val);
                vector<Node *> children = node->children;
                for (int i = children.size() - 1; i >= 0; --i)
                {
                    st.push(children[i]);
                }
            }
        }
        return result;
    }
};

class Solution
{
public:
    void preorder(Node *root, vector<int> &result)
    {
        if (root == nullptr)
        {
            return;
        }
        result.push_back(root->val);
        for (int i = 0; i < root->children.size(); ++i)
        {
            preorder(root->children[i], result);
        }
    }
    vector<int> preorder(Node *root)
    {
        vector<int> result;
        preorder(root, result);
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: root = [1,null,3,2,4,null,5,6]
    // Output: [1,3,5,6,2,4]
    // Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
    // Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]
    return 0;
}