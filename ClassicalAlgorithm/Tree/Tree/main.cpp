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
#include <exception>
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
    void levelOrderBinaryTree(int arr[], int size);
    Node *levelOrderBinaryTree(int arr[], int start, int size);
    void PrintInOrder();
    void PrintInOrder(Node *node);
    void PrintPreOrder();
    void PrintPreOrder(Node *node);
    void PrintPostOrder();
    void PrintPostOrder(Node *node);
    void PrintBreathFirst();
    void PrintDepthFirst();
    int TreeDepth();
    int TreeDepth(Node *root);
    void NthPreOrder(int index);
    void NthPreOrder(Node *node, int index, int &counter);
    void NthPostOrder(int index);
    void NthPostOrder(Node *node, int index, int &counter);
    void NthInOrder(int index);
    void NthInOrder(Node *node, int index, int &counter);
    Tree *CopyTree();
    Tree::Node *CopyTree(Node *curr);
    Tree *CopyMirrorTree();
    Tree::Node *CopyMirrorTree(Node *curr);
    int numNodes();
    int numNodes(Node *curr);
    int numLeafNodes();
    int numLeafNodes(Node *curr);
    bool isEqual(Tree *T2);
    bool Identical(Node *node1, Node *node2);
    void Free();
    void FreeTree(Node *node);
    void printAllPath();
    void printAllPath(Node *curr, std::vector<int> &stk);
    int LCA(int first, int second);
    Tree::Node *LCA(Node *curr, int first, int second);
    int findMaxBT();
    int findMaxBT(Node *curr);
    bool searchBT(Node *root, int value);
    int numFullNodesBT();
    int numFullNodesBT(Node *curr);
    int sumAllBT();
    int sumAllBT(Node *curr);
    void iterativePreOrder();
    void iterativePostOrder();
    void iterativeInOrder();
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

void Tree::PrintBreathFirst()
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

void Tree::NthPreOrder(int index)
{
    int counter = 0;
    NthPreOrder(root, index, counter);
}

void Tree::NthPreOrder(Node *node, int index, int &counter)
{
    if (node != nullptr)
    {
        counter++;
        if (counter == index)
        {
            std::cout << " " << node->value;
        }
        NthPreOrder(node->lChild, index, counter);
        NthPreOrder(node->rChild, index, counter);
    }
}

void Tree::NthPostOrder(int index)
{
    int counter = 0;
    NthPostOrder(root, index, counter);
}

void Tree::NthPostOrder(Node *node, int index, int &counter)
{
    if (node != nullptr)
    {
        NthPostOrder(node->lChild, index, counter);
        NthPostOrder(node->rChild, index, counter);
        counter++;
        if (counter == index)
        {
            std::cout << " " << node->value;
        }
    }
}

void Tree::NthInOrder(int index)
{
    int counter = 0;
    NthInOrder(root, index, counter);
}

void Tree::NthInOrder(Node *node, int index, int &counter)
{
    if (node != nullptr)
    {
        NthInOrder(node->lChild, index, counter);
        counter++;
        if (counter == index)
        {
            std::cout << " " << node->value;
        }
        NthInOrder(node->rChild, index, counter);
    }
}

Tree::Node *Tree::CopyTree(Node *curr)
{
    Node *temp;
    if (curr != nullptr)
    {
        temp = new Node(curr->value);
        temp->lChild = CopyTree(curr->lChild);
        temp->rChild = CopyTree(curr->rChild);
        return temp;
    }
    else
    {
        return nullptr;
    }
}

Tree *Tree::CopyTree()
{
    Tree *tree2 = new Tree();
    tree2->root = CopyTree(root);
    return tree2;
}

Tree *Tree::CopyMirrorTree()
{
    Tree *tree2 = new Tree();
    tree2->root = CopyMirrorTree(root);
    return tree2;
}

Tree::Node *Tree::CopyMirrorTree(Node *curr)
{
    Node *temp;
    if (curr != nullptr)
    {
        temp = new Node(curr->value);
        temp->rChild = CopyMirrorTree(curr->lChild);
        temp->lChild = CopyMirrorTree(curr->rChild);
        return temp;
    }
    else
    {
        return nullptr;
    }
}

int Tree::numNodes()
{
    return numNodes(root);
}

int Tree::numNodes(Node *curr)
{
    if (curr == nullptr)
    {
        return 0;
    }
    else
    {
        return (1 + numNodes(curr->rChild) + numNodes(curr->lChild));
    }
}

int Tree::numLeafNodes()
{
    return numLeafNodes(root);
}

int Tree::numLeafNodes(Node *curr)
{
    if (curr == nullptr)
    {
        return 0;
    }
    if (curr->lChild == nullptr && curr->rChild == nullptr)
    {
        return 1;
    }
    else
    {
        return (numLeafNodes(curr->rChild) + numLeafNodes(curr->lChild));
    }
}

bool Tree::isEqual(Tree *T2)
{
    return Identical(root, T2->root);
}

bool Tree::Identical(Node *node1, Node *node2)
{
    if (node1 == nullptr && node2 == nullptr)
    {
        return true;
    }
    else if (node1 == nullptr || node2 == nullptr)
    {
        return false;
    }
    else
    {
        return (Identical(node1->lChild, node2->lChild) && Identical(node1->rChild, node2->rChild) && (node1->value == node2->value));
    }
}

void Tree::Free()
{
    FreeTree(root);
    root = nullptr;
}
void Tree::FreeTree(Node *node)
{
    if (node)
    {
        FreeTree(node->lChild);
        FreeTree(node->rChild);
        delete (node);
    }
}

void Tree::printAllPath()
{
    std::vector<int> stk;
    printAllPath(root, stk);
}
void Tree::printAllPath(Node *curr, std::vector<int> &stk)
{
    if (curr == nullptr)
    {
        return;
    }
    stk.push_back(curr->value);
    if (curr->lChild == nullptr && curr->rChild == nullptr)
    {
        for (int i = 0; i < stk.size(); i++)
            std::cout << stk[i] << " ";
        stk.pop_back();
        std::cout << std::endl;
        return;
    }
    printAllPath(curr->rChild, stk);
    printAllPath(curr->lChild, stk);
    stk.pop_back();
}

int Tree::LCA(int first, int second)
{
    Node *ans = LCA(root, first, second);
    if (ans != nullptr)
    {
        return ans->value;
    }
    else
    {
        throw std::runtime_error("NotFoundException");
    }
}

Tree::Node *Tree::LCA(Node *curr, int first, int second)
{
    Node *left, *right;
    if (curr == nullptr)
    {
        return nullptr;
    }
    if (curr->value == first || curr->value == second)
    {
        return curr;
    }
    left = LCA(curr->lChild, first, second);
    right = LCA(curr->rChild, first, second);
    if (left != nullptr && right != nullptr)
    {
        return curr;
    }
    else if (left != nullptr)
    {
        return left;
    }
    else
    {
        return right;
    }
}

int Tree::findMaxBT()
{
    int ans = findMaxBT(root);
    return ans;
}
int Tree::findMaxBT(Node *curr)
{
    int left, right;
    if (curr == nullptr)
    {
        return std::numeric_limits<int>::min();
    }
    int max = curr->value;
    left = findMaxBT(curr->lChild);
    right = findMaxBT(curr->rChild);
    if (left > max)
    {
        max = left;
    }
    if (right > max)
    {
        max = right;
    }
    return max;
}

bool Tree::searchBT(Node *root, int value)
{
    bool left, right;
    if (root == nullptr)
        return false;
    if (root->value == value)
        return true;
    left = searchBT(root->lChild, value);
    if (left)
        return true;
    right = searchBT(root->rChild, value);
    if (right)
        return true;
    return false;
}

int Tree::numFullNodesBT()
{
    return numNodes(root);
}
int Tree::numFullNodesBT(Node *curr)
{
    int count;
    if (curr == nullptr)
        return 0;
    count = numFullNodesBT(curr->rChild) + numFullNodesBT(curr->lChild);
    if (curr->rChild != nullptr && curr->lChild != nullptr)
        count++;
    return count;
}

int Tree::sumAllBT()
{
    return sumAllBT(root);
}
int Tree::sumAllBT(Node *curr)
{
    int sum, leftSum, rightSum;
    if (curr == nullptr)
        return 0;
    rightSum = sumAllBT(curr->rChild);
    leftSum = sumAllBT(curr->lChild);
    sum = rightSum + leftSum + curr->value;
    return sum;
}

void Tree::iterativePreOrder()
{
    std::stack<Node *> stk;
    Node *curr;
    if (root != nullptr)
        stk.push(root);
    while (stk.empty() == false)
    {
        curr = stk.top();
        stk.pop();
        std::cout << curr->value << " ";
        if (curr->rChild != nullptr)
            stk.push(curr->rChild);
        if (curr->lChild != nullptr)
            stk.push(curr->lChild);
    }
}

void Tree::iterativePostOrder()
{
    std::stack<Node *> stk;
    std::stack<int> visited;
    Node *curr;
    int vtd;
    if (root != nullptr)
    {
        stk.push(root);
        visited.push(0);
    }
    while (stk.empty() == false)
    {
        curr = stk.top();
        stk.pop();
        vtd = visited.top();
        visited.pop();
        if (vtd == 1)
        {
            std::cout << curr->value << " ";
        }
        else
        {
            stk.push(curr);
            visited.push(1);
            if (curr->rChild != nullptr)
            {
                stk.push(curr->rChild);
                visited.push(0);
            }
            if (curr->lChild != nullptr)
            {
                stk.push(curr->lChild);
                visited.push(0);
            }
        }
    }
}

void Tree::iterativeInOrder()
{
    std::stack<Node *> stk;
    std::stack<int> visited;
    Node *curr;
    int vtd;
    if (root != nullptr)
    {
        stk.push(root);
        visited.push(0);
    }
    while (stk.empty() == false)
    {
        curr = stk.top();
        stk.pop();
        vtd = visited.top();
        visited.pop();
        if (vtd == 1)
            std::cout << curr->value;
        else
        {
            if (curr->rChild != nullptr)
            {
                stk.push(curr->rChild);
                visited.push(0);
            }
            stk.push(curr);
            visited.push(1);
            if (curr->lChild != nullptr)
            {
                stk.push(curr->lChild);
                visited.push(0);
            }
        }
    }
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