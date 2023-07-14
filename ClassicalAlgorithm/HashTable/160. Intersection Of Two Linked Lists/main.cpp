/*
 * File: main.cpp
 * Project: IntersectionOfTwoLinkedLists
 * File Created: Monday, 6th June 2022 11:16:28 am
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *result = nullptr;
        unordered_set<ListNode *> ht;
        ListNode *headATemp = headA;
        while (headATemp)
        {
            ht.insert(headATemp);
            headATemp = headATemp->next;
        }
        ListNode *headBTemp = headB;
        while (headBTemp)
        {
            if (ht.find(headBTemp) != ht.end())
            {
                result = headBTemp;
                break;
            }
            headBTemp = headBTemp->next;
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}