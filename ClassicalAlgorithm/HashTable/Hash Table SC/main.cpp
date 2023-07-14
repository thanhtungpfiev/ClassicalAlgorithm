/*
 * File: main.cpp
 * Project: HashTableSC
 * File Created: Friday, 22nd July 2022 4:26:09 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>

using namespace std;

class HashTableSC
{
private:
    struct Node
    {
        int value;
        Node *next;
        Node(int v, Node *n);
    };
    int tableSize;
    std::vector<Node *> listArray;
    int ComputeHash(int key); // division method
    int PRIME_NUMBER = 11;
public:
    HashTableSC();
    virtual void Add(int value);
    virtual bool Remove(int value);
    virtual void Print();
    virtual bool Find(int value);
};

HashTableSC::Node::Node(int v, Node *n)
{
    value = v;
    next = n;
}
HashTableSC::HashTableSC()
{
    tableSize = PRIME_NUMBER;
    listArray = std::vector<Node *>(tableSize);
    for (int i = 0; i < tableSize; i++)
    {
        listArray[i] = nullptr;
    }
}
void HashTableSC::Add(int value)
{
    int index = ComputeHash(value);
    listArray[index] = new Node(value, listArray[index]);
}
bool HashTableSC::Remove(int value)
{
    int index = ComputeHash(value);
    Node *nextNode, *head = listArray[index];
    Node *delMe;
    if (head != nullptr && head->value == value)
    {
        delMe = head;
        listArray[index] = head->next;
        delete (delMe);
        return true;
    }
    while (head != nullptr)
    {
        nextNode = head->next;
        if (nextNode != nullptr && nextNode->value == value)
        {
            delMe = head->next;
            head->next = nextNode->next;
            delete (delMe);
            return true;
        }
        else
        {
            head = nextNode;
        }
    }
    return false;
}
void HashTableSC::Print()
{
    for (int i = 0; i < tableSize; i++)
    {
        Node *head = listArray[i];
        if (head)
            std::cout << "Index:: " << i << "Value :: " << std::endl;
        while (head != nullptr)
        {
            std::cout << head->value << std::endl;
            head = head->next;
        }
    }
}
bool HashTableSC::Find(int value)
{
    int index = ComputeHash(value);
    Node *head = listArray[index];
    while (head != nullptr)
    {
        if (head->value == value)
            return true;
        head = head->next;
    }
    return false;
}

int HashTableSC::ComputeHash(int key)
{
    return key % tableSize;
}

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}