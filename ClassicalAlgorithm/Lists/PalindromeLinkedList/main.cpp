/*
 * File: main.cpp
 * Project: PalindromeLinkedList
 * File Created: Friday, 19th August 2022 1:49:05 pm
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
    bool isPalindrome(ListNode *head)
    {
        vector<int> v;
        ListNode *curr = head;
        while (curr)
        {
            v.push_back(curr->val);
            curr = curr->next;
        }
        int left = 0, right = v.size() - 1;
        while (left <= right)
        {
            if (v[left] == v[right])
            {
                ++left;
                --right;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *prev = nullptr, *third = nullptr;
        while (slow)
        {
            third = slow->next;
            slow->next = prev;
            prev = slow;
            slow = third;
        }
        fast = head, slow = prev;
        while (slow)
        {
            if (slow->val != fast->val)
                return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: head = [1,2,2,1]
    // Output: true

    // Input: head = [1,2]
    // Output: false
    return 0;
}