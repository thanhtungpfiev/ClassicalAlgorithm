/*
 * File: main.cpp
 * Project: 208. Implement Trie (Prefix Tree)
 * File Created: Tuesday, 8th August 2023 9:19:00 pm
 * Author: Dao Thanh Tung (MS/EDA101-XC) (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TrieNode
{

    // pointer array for child nodes of each node
    TrieNode *childNode[26];
    int wordCount;

    TrieNode()
    {
        // constructor
        // initialize the wordCnt variable with 0
        // initialize every index of childNode array with
        // NULL
        wordCount = 0;
        for (int i = 0; i < 26; i++)
        {
            childNode[i] = NULL;
        }
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert_key(TrieNode *root, string &key)
    {
        // Initialize the currentNode pointer
        // with the root node
        TrieNode *currentNode = root;

        // Iterate across the length of the string
        for (auto c : key)
        {

            // Check if the node exist for the current
            // character in the Trie.
            int index = c - 'a';
            if (currentNode->childNode[index] == NULL)
            {

                // If node for current character does not exist
                // then make a new node
                TrieNode *newNode = new TrieNode();

                // Keep the reference for the newly created
                // node.
                currentNode->childNode[index] = newNode;
            }

            // Now, move the current node pointer to the newly
            // created node.
            currentNode = currentNode->childNode[index];
        }

        // Increment the wordEndCount for the last currentNode
        // pointer this implies that there is a string ending at
        // currentNode.
        currentNode->wordCount++;
    }

    bool search_key(TrieNode *root, string &key)
    {
        // Initialize the currentNode pointer
        // with the root node
        TrieNode *currentNode = root;

        // Iterate across the length of the string
        for (auto c : key)
        {

            // Check if the node exist for the current
            // character in the Trie.
            int index = c - 'a';
            if (currentNode->childNode[index] == NULL)
            {

                // Given word does not exist in Trie
                return false;
            }

            // Move the currentNode pointer to the already
            // existing node for current character.
            currentNode = currentNode->childNode[index];
        }

        return (currentNode->wordCount > 0);
    }

    bool isPrefixExist(TrieNode *root, string &key)
    {
        // Initialize the currentNode pointer
        // with the root node
        TrieNode *currentNode = root;

        // Iterate across the length of the string
        for (auto c : key)
        {

            // Check if the node exist for the current
            // character in the Trie.
            int index = c - 'a';
            if (currentNode->childNode[index] == NULL)
            {

                // Given word as a prefix does not exist in Trie
                return false;
            }

            // Move the currentNode pointer to the already
            // existing node for current character.
            currentNode = currentNode->childNode[index];
        }

        // Prefix exist in the Trie
        return true;
    }

    void insert(string word)
    {
        insert_key(root, word);
    }

    bool search(string word)
    {
        return search_key(root, word);
    }

    bool startsWith(string prefix)
    {
        return isPrefixExist(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}