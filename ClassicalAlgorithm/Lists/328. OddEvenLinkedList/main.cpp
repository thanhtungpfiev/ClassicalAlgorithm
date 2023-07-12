/*
 * File: main.cpp
 * Project: OddEvenLinkedList
 * File Created: Monday, 22nd August 2022 2:18:17 pm
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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode *odd = head, *even = head->next, *evenHead = even;
        // `even != null` rules out the list of only 1 node
        // `even.next != null` rules out the list of only 2 nodes
        while (even && even->next)
        {
            // Put odd to the odd list
            odd->next = odd->next->next;

            // Put even to the even list
            even->next = even->next->next;

            // Move the pointer to the next odd/even
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: head = [1,2,3,4,5]
    // Output: [1,3,5,2,4]

    // Input: head = [2,1,3,5,6,4,7]
    // Output: [2,3,6,7,1,5,4]
    return 0;
}