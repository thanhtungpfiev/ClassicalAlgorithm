/*
 * File: main.cpp
 * Project: RemoveNthNodeFromEndOfList
 * File Created: Friday, 19th August 2022 9:39:39 am
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        int length = 0;
        ListNode *curr = head;
        while (curr)
        {
            ++length;
            curr = curr->next;
        }
        if (length < n)
        {
            return nullptr;
        }

        if (length == n)
        {
            if (n == 1)
            {
                return nullptr;
            }
            else
            {
                return head->next;
            }
        }
        else
        {
            int k = length - n - 1;
            curr = head;
            while (k > 0)
            {
                curr = curr->next;
                --k;
            }
            curr->next = curr->next->next;
        }
        return head;
    }
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < n; ++i)
        {
            fast = fast->next;
        }
        if (!fast)
            return head->next;
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: head = [1,2,3,4,5], n = 2
    // Output: [1,2,3,5]

    // Input: head = [1], n = 1
    // Output: []

    // Input: head = [1,2], n = 1
    // Output: [1]
    return 0;
}