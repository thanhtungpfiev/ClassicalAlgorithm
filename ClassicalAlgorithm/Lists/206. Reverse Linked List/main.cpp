/*
 * File: main.cpp
 * Project: ReverseLinkedList
 * File Created: Wednesday, 20th July 2022 2:11:55 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode *curr = head;
        ListNode *prev = nullptr;
        ListNode *third = nullptr;
        while (curr)
        {
            third = curr->next;
            curr->next = prev;
            prev = curr;
            curr = third;
        }
        head = prev;
        return head;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: head = [1,2,3,4,5]
    // Output: [5,4,3,2,1]
    // Input: head = [1,2]
    // Output: [2,1]
    // Input: head = []
    // Output: []
    return 0;
}