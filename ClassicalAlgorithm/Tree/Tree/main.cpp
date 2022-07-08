/*
 * File: main.cpp
 * Project: Tree
 * File Created: Friday, 8th July 2022 3:47:16 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Tree
{
private:
    struct Node
    {
        int value;
        Node *lChild;
        Node *rChild;
        Node(int v, Node *l, Node *r);
        Node(int v);
    };
    Node *root;

public:
    Tree();
    void levelOrderBinaryTree(int arr[], int size);
    Node *levelOrderBinaryTree(int arr[], int start, int size);
    void PrintInOrder();
    void PrintInOrder(Node *node);
    void PrintPreOrder();
    void PrintPreOrder(Node *node);
    void PrintPostOrder();
    void PrintPostOrder(Node *node);
    void PrintBredthFirst();
    void PrintDepthFirst();
    int TreeDepth();
    int TreeDepth(Node *root);
};

Tree::Node::Node(int v, Node *l, Node *r)
{
    value = v;
    lChild = l;
    rChild = r;
}

Tree::Node::Node(int v)
{
    value = v;
    lChild = nullptr;
    rChild = nullptr;
}

Tree::Tree()
{
    root = nullptr;
}

void Tree::levelOrderBinaryTree(int arr[], int size)
{
    root = levelOrderBinaryTree(arr, 0, size);
}

Tree::Node *Tree::levelOrderBinaryTree(int arr[], int start, int size)
{
    Node *curr = new Node(arr[start]);
    int left = 2 * start + 1;
    int right = 2 * start + 2;
    if (left < size)
    {
        curr->lChild = levelOrderBinaryTree(arr, left, size);
    }
    if (right < size)
    {
        curr->rChild = levelOrderBinaryTree(arr, right, size);
    }
    return curr;
}

void Tree::PrintInOrder()
{
    PrintInOrder(root);
}

void Tree::PrintInOrder(Node *node)
{
    if (node != nullptr)
    {
        PrintInOrder(node->lChild);
        cout << " " << node->value;
        PrintInOrder(node->rChild);
    }
}

void Tree::PrintPreOrder()
{
    PrintPreOrder(root);
}

void Tree::PrintPreOrder(Node *node)
{
    if (node != nullptr)
    {
        cout << " " << node->value;
        PrintPreOrder(node->lChild);
        PrintPreOrder(node->rChild);
    }
}

void Tree::PrintPostOrder()
{
    PrintPostOrder(root);
}

void Tree::PrintPostOrder(Node *node)
{
    if (node != nullptr)
    {
        PrintPostOrder(node->lChild);
        PrintPostOrder(node->rChild);
        cout << " " << node->value;
    }
}

void Tree::PrintBredthFirst()
{
    std::queue<Node *> que;
    Node *temp;
    if (root != nullptr)
    {
        que.push(root);
    }
    while (que.empty() == false)
    {
        temp = que.front();
        que.pop();
        std::cout << temp->value << std::endl;
        if (temp->lChild != nullptr)
        {
            que.push(temp->lChild);
        }
        if (temp->rChild != nullptr)
        {
            que.push(temp->rChild);
        }
    }
}

void Tree::PrintDepthFirst()
{
    std::stack<Node *> stk;
    Node *temp;
    if (root != nullptr)
    {
        stk.push(root);
    }
    while (stk.empty() == false)
    {
        temp = stk.top();
        stk.pop();
        std::cout << temp->value << std::endl;
        if (temp->lChild != nullptr)
        {
            stk.push(temp->lChild);
        }
        if (temp->rChild != nullptr)
        {
            stk.push(temp->rChild);
        }
    }
}

int Tree::TreeDepth(Node *root)
{
    if (root == nullptr)
        return 0;
    int lDepth = TreeDepth(root->lChild);
    int rDepth = TreeDepth(root->rChild);
    if (lDepth > rDepth)
        return lDepth + 1;
    else
        return rDepth + 1;
}
int Tree::TreeDepth()
{
    return TreeDepth(root);
}

int main(int argc, char **argv)
{
    Tree t;
    int arr[] = {6, 4, 8, 2, 5, 7, 9, 1, 3, 10};
    t.levelOrderBinaryTree(arr, 10);
    t.PrintInOrder();
    cout << endl;
    t.PrintPreOrder();
    cout << endl;
    t.PrintPostOrder();
    return 0;
}