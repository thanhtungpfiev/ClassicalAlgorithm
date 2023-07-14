/*
 * File: main.cpp
 * Project: PartitionList
 * File Created: Friday, 22nd July 2022 10:09:39 am
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
    ListNode *partition(ListNode *head, int x)
    {
        // before and after are the two pointers used to create the two list
        // before_head and after_head are used to save the heads of the two lists.
        // All of these are initialized with the dummy nodes created.
        ListNode *before_head = new ListNode(0);
        ListNode *before = before_head;
        ListNode *after_head = new ListNode(0);
        ListNode *after = after_head;

        while (head)
        {
            // If the original list node is lesser than the given x,
            // assign it to the before list.
            if (head->val < x)
            {
                before->next = head;
                before = before->next;
            }
            else
            {
                // If the original list node is greater or equal to the given x,
                // assign it to the after list.
                after->next = head;
                after = after->next;
            }
            // move ahead in the original list
            head = head->next;
        }
        // Last node of "after" list would also be ending node of the reformed list
        after->next = nullptr;

        // Once all the nodes are correctly assigned to the two lists,
        // combine them to form a single list which would be returned.
        before->next = after_head->next;
        return before_head->next;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: head = [1,4,3,2,5,2], x = 3
    // Output: [1,2,2,4,3,5]
    // Input: head = [2,1], x = 2
    // Output: [1,2]
    return 0;
}