/*
 * File: main1.cpp
 * Project: BinarySearchTree
 * File Created: Friday, 15th July 2022 10:48:52 am
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <limits>

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
    void CreateBinaryTree(int arr[], int size);
    Tree::Node *CreateBinaryTree(int arr[], int start, int end);
    void InsertNode(int value);
    Tree::Node *InsertNode(int value, Node *node);
    bool Find(int value);
    bool Find2(int value);
    int FindMin();
    int FindMax();
    bool isBST3(Node *root);
    bool isBST();
    bool isBST(Node *root, int min, int max);
    Tree::Node *FindMin(Node *root);
    Tree::Node *FindMax(Node *root);
    bool isBST2();
    bool isBST2(Node *root, int &count);
    void DeleteNode(int value);
    Tree::Node *DeleteNode(Node *node, int value);
    int LcaBST(int first, int second);
    int LcaBST(Node *curr, int first, int second);
    Tree::Node *trimOutsideRange(Node *curr, int min, int max);
    void trimOutsideRange(int min, int max);
    void printInRange(int min, int max);
    void printInRange(Node *root, int min, int max);
    int FloorBST(int val);
    int CeilBST(int val);
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

void Tree::CreateBinaryTree(int arr[], int size)
{
    root = CreateBinaryTree(arr, 0, size - 1);
}

Tree::Node *Tree::CreateBinaryTree(int arr[], int start, int end)
{
    Node *curr = nullptr;
    if (start > end)
        return nullptr;
    int mid = (start + end) / 2;
    curr = new Node(arr[mid]);
    curr->lChild = CreateBinaryTree(arr, start, mid - 1);
    curr->rChild = CreateBinaryTree(arr, mid + 1, end);
    return curr;
}

void Tree::InsertNode(int value)
{
    root = InsertNode(value, root);
}
Tree::Node *Tree::InsertNode(int value, Node *node)
{
    if (node == nullptr)
    {
        node = new Node(value, nullptr, nullptr);
    }
    else
    {
        if (node->value > value)
        {
            node->lChild = InsertNode(value, node->lChild);
        }
        else
        {
            node->rChild = InsertNode(value, node->rChild);
        }
    }
    return node;
}

bool Tree::Find(int value)
{
    Node *curr = root;
    while (curr != nullptr)
    {
        if (curr->value == value)
        {
            return true;
        }
        else if (curr->value > value)
        {
            curr = curr->lChild;
        }
        else
        {
            curr = curr->rChild;
        }
    }
    return false;
}

bool Tree::Find2(int value)
{
    Node *curr = root;
    while (curr != nullptr && curr->value != value)
    {
        curr = (curr->value > value) ? curr->lChild : curr->rChild;
    }
    return curr != nullptr;
}

int Tree::FindMin()
{
    Node *node = root;
    if (node == nullptr)
    {
        throw std::runtime_error("EmptyTreeException");
    }
    while (node->lChild != nullptr)
    {
        node = node->lChild;
    }
    return node->value;
}

int Tree::FindMax()
{
    Node *node = root;
    if (node == nullptr)
    {
        throw std::runtime_error("EmptyTreeException");
    }
    while (node->rChild != nullptr)
    {
        node = node->rChild;
    }
    return node->value;
}

bool Tree::isBST3(Node *root)
{
    if (root == nullptr)
    {
        return true;
    }
    if (root->lChild != nullptr && FindMax(root->lChild)->value > root->value)
    {
        return false;
    }
    if (root->rChild != nullptr && FindMin(root->rChild)->value <= root->value)
    {
        return false;
    }
    return (isBST3(root->lChild) && isBST3(root->rChild));
}

bool Tree::isBST()
{
    return isBST(root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}
bool Tree::isBST(Node *curr, int min, int max)
{
    if (curr == nullptr)
        return true;
    if (curr->value < min || curr->value > max)
        return false;
    return isBST(curr->lChild, min, curr->value) && isBST(curr->rChild, curr->value, max);
}

bool Tree::isBST2()
{
    int c;
    return isBST2(root, c);
}
bool Tree::isBST2(Node *root, int &count)
{
    bool ret;
    if (root != nullptr)
    {
        ret = isBST2(root->lChild, count);
        if (!ret)
            return false;
        if (count > root->value)
            return false;
        count = root->value;
        ret = isBST2(root->rChild, count);
        if (!ret)
            return false;
    }
    return true;
}

Tree::Node *Tree::FindMin(Node *root)
{
}

Tree::Node *Tree::FindMax(Node *root)
{
}

void Tree::DeleteNode(int value)
{
    root = DeleteNode(root, value);
}
Tree::Node *Tree::DeleteNode(Node *node, int value)
{
    Node *temp = nullptr;
    if (node != nullptr)
    {
        if (node->value == value)
        {
            if (node->lChild == nullptr && node->rChild == nullptr)
            {
                delete node;
                return nullptr;
            }
            else
            {
                if (node->lChild == nullptr)
                {
                    temp = node->rChild;
                    delete node;
                    return temp;
                }
                if (node->rChild == nullptr)
                {
                    temp = node->lChild;
                    delete node;
                    return temp;
                }
                Node *maxNode = FindMax(node->lChild);
                int maxValue = maxNode->value;
                node->value = maxValue;
                node->lChild = DeleteNode(node->lChild, maxValue);
            }
        }
        else
        {
            if (node->value > value)
            {
                node->lChild = DeleteNode(node->lChild, value);
            }
            else
            {
                node->rChild = DeleteNode(node->rChild, value);
            }
        }
    }
    return node;
}

int Tree::LcaBST(int first, int second)
{
    return LcaBST(root, first, second);
}
int Tree::LcaBST(Node *curr, int first, int second)
{
    if (curr == nullptr)
    {
        throw std::runtime_error("NotFoundException");
    }
    if (curr->value > first && curr->value > second)
    {
        return LcaBST(curr->lChild, first, second);
    }
    if (curr->value < first && curr->value < second)
    {
        return LcaBST(curr->rChild, first, second);
    }
    return curr->value;
}

Tree::Node *Tree::trimOutsideRange(Node *curr, int min, int max)
{
    if (curr == nullptr)
        return nullptr;
    curr->lChild = trimOutsideRange(curr->lChild, min, max);
    curr->rChild = trimOutsideRange(curr->rChild, min, max);
    if (curr->value < min)
        return curr->rChild;
    if (curr->value > max)
        return curr->lChild;
    return curr;
}
void Tree::trimOutsideRange(int min, int max)
{
    trimOutsideRange(root, min, max);
}

void Tree::printInRange(int min, int max)
{
    printInRange(root, min, max);
}
void Tree::printInRange(Node *root, int min, int max)
{
    if (root == nullptr)
        return;
    printInRange(root->lChild, min, max);
    if (root->value >= min && root->value <= max)
        std::cout << root->value << " ";
    printInRange(root->rChild, min, max);
}

int Tree::FloorBST(int val)
{
    Node *curr = root;
    int floor = std::numeric_limits<int>::max();
    while (curr != nullptr)
    {
        if (curr->value == val)
        {
            floor = curr->value;
            break;
        }
        else if (curr->value > val)
        {
            curr = curr->lChild;
        }
        else
        {
            floor = curr->value;
            curr = curr->rChild;
        }
    }
    return floor;
}
int Tree::CeilBST(int val)
{
    Node *curr = root;
    int ceil = std::numeric_limits<int>::min();
    while (curr != nullptr)
    {
        if (curr->value == val)
        {
            ceil = curr->value;
            break;
        }
        else if (curr->value > val)
        {
            ceil = curr->value;
            curr = curr->lChild;
        }
        else
        {
            curr = curr->rChild;
        }
    }
    return ceil;
}

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}
