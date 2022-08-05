/*
 * File: main.cpp
 * Project: MergeTwoSortedLists
 * File Created: Wednesday, 20th July 2022 2:08:00 pm
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // if list1 happen to be NULL
        // we will simply return list2.
        if (list1 == nullptr)
        {
            return list2;
        }

        // if list2 happen to be NULL
        // we will simply return list1.
        if (list2 == nullptr)
        {
            return list1;
        }

        // if value pointend by l1 pointer is less than equal to value pointed by l2 pointer
        // we wall call recursively l1 -> next and whole l2 list.
        if (list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        // we will call recursive l1 whole list and l2 -> next
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: list1 = [1,2,4], list2 = [1,3,4]
    // Output: [1,1,2,3,4,4]
    // Input: list1 = [], list2 = []
    // Output: []
    // Input: list1 = [], list2 = [0]
    // Output: [0]
    return 0;
}