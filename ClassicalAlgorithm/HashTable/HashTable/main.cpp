/*
 * File: main.cpp
 * Project: HashTable
 * File Created: Wednesday, 20th July 2022 4:57:06 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>

using namespace std;

class HashTable
{
private:
    static int EMPTY_NODE;
    static int LAZY_DELETED;
    static int FILLED_NODE;
    std::vector<int> Arr;
    std::vector<int> Flag;
    int tableSize = 0;
    virtual int ComputeHash(int key);
    virtual int ResolverFun(int index);

public:
    HashTable(int tSize);
    virtual bool Add(int value);
    virtual bool Find(int value);
    virtual bool Remove(int value);
    virtual void Print();
};

int HashTable::EMPTY_NODE = 50;
int HashTable::LAZY_DELETED = 50;
int HashTable::FILLED_NODE = 50;

HashTable::HashTable(int tSize) : tableSize(tSize), Arr(tSize), Flag(tSize)
{
}

int HashTable::ComputeHash(int key)
{
    return key % tableSize;
}

int HashTable::ResolverFun(int index)
{
    return index;
}

bool HashTable::Add(int value)
{
    int hashValue = ComputeHash(value);
    for (int i = 0; i < tableSize; i++)
    {
        if (Flag[hashValue] == EMPTY_NODE || Flag[hashValue] == LAZY_DELETED)
        {
            Arr[hashValue] = value;
            Flag[hashValue] = FILLED_NODE;
            return true;
        }
        hashValue += ResolverFun(i);
        hashValue %= tableSize;
    }
    return false;
}

bool HashTable::Find(int value)
{
    int hashValue = ComputeHash(value);
    for (int i = 0; i < tableSize; i++)
    {
        if (Flag[hashValue] == EMPTY_NODE)
            return false;
        if (Flag[hashValue] == FILLED_NODE && Arr[hashValue] == value)
            return true;
        hashValue += ResolverFun(i);
        hashValue %= tableSize;
    }
    return false;
}

bool HashTable::Remove(int value)
{
    int hashValue = ComputeHash(value);
    for (int i = 0; i < tableSize; i++)
    {
        if (Flag[hashValue] == EMPTY_NODE)
            return false;
        if (Flag[hashValue] == FILLED_NODE && Arr[hashValue] == value)
        {
            Flag[hashValue] = LAZY_DELETED;
            return true;
        }
        hashValue += ResolverFun(i);
        hashValue %= tableSize;
    }
    return false;
}

void HashTable::Print()
{
    std::cout << "\nValues Stored in HashTable are::" << std::endl;
    for (int i = 0; i < tableSize; i++)
    {
        if (Flag[i] == FILLED_NODE)
            std::cout << "Node at index [" << i << " ] :: " << Arr[i] << std::endl;
    }
}

int main(int argc, char **argv)
{
    HashTable *ht = new HashTable(1000);
    ht->Add(89);
    ht->Add(18);
    ht->Add(49);
    ht->Add(58);
    ht->Add(69);
    ht->Add(89);
    ht->Add(18);
    ht->Add(49);
    ht->Add(58);
    ht->Add(69);
    ht->Print();
    ht->Remove(89);
    ht->Remove(18);
    ht->Remove(49);
    ht->Remove(58);
    ht->Remove(69);
    ht->Print();
    return 0;
}