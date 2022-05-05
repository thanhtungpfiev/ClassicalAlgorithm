/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 8/28/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>

using namespace std;

struct Node
{
    int data = 0;
    Node* left = nullptr;
    Node* right = nullptr;

};

/* Function to create a new node */

Node* CreateNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

void FreeNode(Node* root)
{
    if (root == nullptr) {
        return;
    }
    FreeNode(root->left);
    FreeNode(root->right);
    delete root;
    root = nullptr;
}

bool LeftOf(int value, const Node* root)
{
    if (root == nullptr) {
        return false;
    }
    return value < root->data;
}

bool RightOf(int value, const Node* root)
{
    if (root == nullptr) {
        return false;
    }
    return value > root->data;
}

Node* Insert(Node* root, int value)
{
    if (root == nullptr) {
        Node* node = CreateNode(value);
        return node;
    }
    if (LeftOf(value, root)) {
        root->left = Insert(root->left, value);
    } else if (RightOf(value, root)){
        root->right = Insert(root->right, value);
    }
    return root;
}

bool Search(const Node* root, int value)
{
    if (root == nullptr) {
        return false;
    }
    if (root->data == value) {
        return true;
    } else if (LeftOf(value, root)) {
        return Search(root->left, value);
    } else if (RightOf(value, root)) {
        return Search(root->right, value);
    }
}

int LeftMostValue(const Node* root)
{
    if (root == nullptr) {
        return -1;
    }
    while (root->left != nullptr) {
        root = root->left;
    }
    return root->data;
}

int RightMostValue(const Node* root)
{
    if (root == nullptr) {
        return -1;
    }
    while (root->right != nullptr) {
        root = root->right;
    }
    return root->data;
}

Node* Delete(Node* root, int value)
{
    if (root == nullptr) {
        return root;
    }
    if (LeftOf(value, root)) {
        root->left = Delete(root->left, value);
    } else if (RightOf(value, root)) {
        root->right = Delete(root->right, value);
    } else {
        if (root->left == nullptr) {
            Node* newRoot = root->right;
            FreeNode(root);
            return newRoot;
        } else if (root->right == nullptr) {
            Node* newRoot = root->left;
            FreeNode(root);
            return newRoot;
        }
        root->data = LeftMostValue(root->right);
        root->right = Delete(root->right, root->data);
    }
    return root;
}

void InOrder(Node* root)
{
    if (root == nullptr) {
        return;
    }
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

int main()
{
    Node* root = nullptr;
    root = Insert(root, 25);
    root = Insert(root, 15);
    root = Insert(root, 50);
    root = Insert(root, 10);
    root = Insert(root, 22);
    root = Insert(root, 35);
    root = Insert(root, 70);
    root = Insert(root, 4);
    root = Insert(root, 12);
    root = Insert(root, 18);
    root = Insert(root, 24);
    root = Insert(root, 31);
    root = Insert(root, 44);
    root = Insert(root, 66);
    root = Insert(root, 90);
    InOrder(root);
    cout << endl;
    root = Delete(root, 66);
    InOrder(root);
    cout << endl;
    root = Delete(root, 70);
    InOrder(root);
    cout << endl;
    root = Delete(root, 50);
    InOrder(root);
    cout << endl;
    FreeNode(root);
    return 0;
}
