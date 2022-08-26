/*
 * File: main.cpp
 * Project: SortList
 * File Created: Monday, 22nd August 2022 2:43:10 pm
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
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode *curr = head;
        vector<int> v;
        while (curr)
        {
            v.push_back(curr->val);
            curr = curr->next;
        }
        sort(v.begin(), v.end());
        head = new ListNode(v[0]);
        ListNode *curr_head = head;
        for (int i = 1; i < v.size(); ++i)
        {
            curr_head->next = new ListNode(v[i]);
            curr_head = curr_head->next;
        }
        return head;
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: head = [4,2,1,3]
    // Output: [1,2,3,4]

    // Input: head = [-1,5,3,4,0]
    // Output: [-1,0,3,4,5]

    // Input: head = []
    // Output: []
    return 0;
}