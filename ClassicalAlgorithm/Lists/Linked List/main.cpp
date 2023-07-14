/*
 * File: main.cpp
 * Project: LinkedList
 * File Created: Friday, 17th June 2022 3:25:23 pm
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <stdexcept>

using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int value = 0;
        Node *next = nullptr;
        Node(int v, Node *n);
        Node(int v);
    };
    Node *head = nullptr;
    int list_size = 0;

public:
    virtual int size();
    virtual bool isEmpty();
    virtual int peek();
    virtual void addHead(int value);
    virtual void addTail(int value);
    virtual int removeHead();
    virtual bool deleteNode(int value);
    virtual void deleteNodes(int delValue);
    virtual void freeList();
    virtual void print();
    virtual void sortedInsert(int value);
    virtual bool isPresent(int value);
    virtual void reverse();
    virtual Node *reverseRecurseUtil(Node *currNode, Node *nextNode);
    virtual void reverseRecurse();
    virtual void removeDuplicate();
    virtual LinkedList *copyReversed();
    virtual LinkedList *copyList();
    virtual bool compareList(Node *head1, Node *head2);
    virtual bool compareList(LinkedList *ll);
    virtual int findLength();
    virtual int nthNodeFromBegining(int index);
    virtual int nthNodeFromEnd(int index);
    virtual int nthNodeFromEnd2(int index);
    virtual bool loopDetect();
    virtual bool reverseListLoopDetect();
    virtual int loopTypeDetect();
    virtual void removeLoop();
    virtual Node *loopPointDetect();
    virtual Node *findIntersection(Node *head, Node *head2);
};

LinkedList::Node::Node(int v, Node *n)
{
    value = v;
    next = n;
}

LinkedList::Node::Node(int v)
{
    value = v;
    next = nullptr;
}

int LinkedList::size()
{
    return list_size;
}

bool LinkedList::isEmpty()
{
    return list_size == 0;
}

int LinkedList::peek()
{
}

void LinkedList::addHead(int value)
{
    head = new Node(value, head);
    list_size++;
}

void LinkedList::addTail(int value)
{
    Node *newNode = new Node(value, nullptr);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *currNode = head;
        while (currNode->next != nullptr)
        {
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }
    list_size++;
}

int LinkedList::removeHead()
{
    if (isEmpty())
    {
        throw std::runtime_error("LinkedList::removeHead");
    }
    Node *deleteMe = head;
    int value = head->value;
    head = head->next;
    list_size--;
    delete deleteMe;
    return value;
}

bool LinkedList::deleteNode(int value)
{
    Node *temp = head;
    Node *deleteMe;
    if (isEmpty())
    {
        throw std::runtime_error("LinkedList::deleteNode");
    }
    if (value == head->value)
    {
        deleteMe = head;
        head = head->next;
        list_size--;
        delete deleteMe;
        return true;
    }
    while (temp->next != nullptr)
    {
        if (temp->next->value == value)
        {
            deleteMe = temp->next;
            temp->next = temp->next->next;
            list_size--;
            delete deleteMe;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void LinkedList::deleteNodes(int delValue)
{
    Node *currNode = head;
    Node *nextNode;
    Node *deleteMe;

    if (isEmpty())
    {
        throw std::runtime_error("LinkedList::deleteNodes");
    }

    while (currNode != nullptr && currNode->value == delValue)
    {
        deleteMe = head;
        head = currNode->next;
        currNode = head;
        delete deleteMe;
    }

    while (currNode != nullptr)
    {
        nextNode = currNode->next;
        if (nextNode->value == delValue)
        {
            deleteMe = nextNode;
            currNode->next = nextNode->next;
            delete deleteMe;
        }
        else
        {
            currNode = nextNode;
        }
    }
}

void LinkedList::freeList()
{
    if (isEmpty())
    {
        throw std::runtime_error("LinkedList::deleteNodes");
    }

    Node *currNode = head;
    Node *nextNode;
    while (currNode != nullptr)
    {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
    head = nullptr;
    list_size = 0;
}

void LinkedList::print()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

void LinkedList::sortedInsert(int value)
{
    Node *newNode = new Node(value);
    Node *currNode = head;
    if (currNode == nullptr || currNode->value > value)
    {
        newNode->next = head;
        head = newNode;
        list_size++;
        return;
    }
    while (currNode->next != nullptr && currNode->next->value < value)
    {
        currNode = currNode->next;
    }
    newNode->next = currNode->next;
    currNode->next = newNode;
    list_size++;
}

bool LinkedList::isPresent(int value)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->value == value)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void LinkedList::reverse()
{
    Node *currNode = head;
    Node *prevNode = nullptr;
    Node *nextNode = nullptr;
    while (currNode != nullptr)
    {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    head = prevNode;
}

void LinkedList::reverseRecurse()
{
    head = reverseRecurseUtil(head, nullptr);
}

void LinkedList::removeDuplicate()
{
    Node *currNode = head;
    Node *deleteMe;
    while (currNode != nullptr)
    {
        if (currNode->next != nullptr && currNode->value == currNode->next->value)
        {
            deleteMe = currNode->next;
            currNode->next = currNode->next->next;
            delete deleteMe;
        }
        else
        {
            currNode = currNode->next;
        }
    }
}

LinkedList *LinkedList::copyReversed()
{
    Node *currNode = head;
    Node *tempNode = nullptr;
    Node *tempNode2 = nullptr;
    while (currNode != nullptr)
    {
        tempNode = new Node(currNode->value, tempNode2);
        currNode = currNode->next;
        tempNode2 = tempNode;
    }
    LinkedList *ll2 = new LinkedList();
    ll2->head = tempNode;
    return ll2;
}

LinkedList *LinkedList::copyList()
{
    LinkedList *ll2 = new LinkedList();
    Node *currNode = head;
    while (currNode != nullptr)
    {
        ll2->addTail(currNode->value);
        currNode = currNode->next;
    }
    return ll2;
}

bool LinkedList::compareList(Node *head1, Node *head2)
{
    if (head1 == nullptr && head2 == nullptr)
    {
        return true;
    }
    else if (head1 == nullptr || head2 == nullptr || head1->value != head2->value)
    {
        return false;
    }
    else
    {
        return compareList(head1->next, head2->next);
    }
}

bool LinkedList::compareList(LinkedList *ll)
{

    return compareList(head, ll->head);
}

int LinkedList::findLength()
{
    Node *curr = head;
    int count = 0;
    while (curr != nullptr)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

int LinkedList::nthNodeFromBegining(int index)
{
    if (index > size() || index < 1)
    {
        throw std::runtime_error("TooFewNodes");
    }
    int count = 0;
    Node *curr = head;
    while (curr != nullptr && count < index - 1)
    {
        count++;
        curr = curr->next;
    }
    return curr->value;
}

int LinkedList::nthNodeFromEnd(int index)
{
    int size = findLength();
    int startIndex;
    if (size != 0 && size < index)
    {
        throw std::runtime_error("TooFewNodes");
    }
    startIndex = size - index + 1;
    return nthNodeFromBegining(startIndex);
}

int LinkedList::nthNodeFromEnd2(int index)
{
    int count = 1;
    Node *forward = head;
    Node *curr = head;
    while (forward != nullptr && count <= index)
    {
        count++;
        forward = forward->next;
    }
    if (forward == nullptr)
    {
        throw std::runtime_error("TooFewNodes");
    }
    while (forward != nullptr)
    {
        forward = forward->next;
        curr = curr->next;
    }
    return curr->value;
}

LinkedList::Node *LinkedList::reverseRecurseUtil(Node *currNode, Node *nextNode)
{
    Node *ret;
    if (currNode == nullptr)
    {
        return nullptr;
    }
    if (currNode->next == nullptr)
    {
        currNode->next = nextNode;
        return currNode;
    }
    ret = reverseRecurseUtil(currNode->next, currNode);
    currNode->next = nextNode;
    return ret;
}

bool LinkedList::loopDetect()
{
    Node *slowPtr;
    Node *fastPtr;
    slowPtr = fastPtr = head;
    while (fastPtr->next != nullptr && fastPtr->next->next != nullptr)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (slowPtr == fastPtr)
        {
            std::cout << "loop found" << std::endl;
            return true;
        }
    }
    std::cout
        << "loop not found" << std::endl;
    return false;
}

bool LinkedList::reverseListLoopDetect()
{
    Node *tempHead = head;
    reverse();
    if (tempHead == head)
    {
        reverse();
        std::cout << "loop found" << std::endl;
        return true;
    }
    else
    {
        reverse();
        std::cout << "loop not found" << std::endl;
        return false;
    }
}

int LinkedList::loopTypeDetect()
{
    Node *slowPtr;
    Node *fastPtr;
    slowPtr = fastPtr = head;
    while (fastPtr->next != nullptr && fastPtr->next->next != nullptr)
    {
        if (head == fastPtr->next || head == fastPtr->next->next)
        {
            std::cout << "circular list loop found" << std::endl;
            return 2;
        }
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (slowPtr == fastPtr)
        {
            std::cout << "loop found" << std::endl;
            return 1;
        }
    }
    std::cout
        << "loop not found" << std::endl;
    return 0;
}

void LinkedList::removeLoop()
{
    Node *loopPoint = loopPointDetect();
    if (loopPoint == nullptr)
    {
        return;
    }
    Node *firstPtr = head;
    if (loopPoint == head)
    {
        while (firstPtr->next != head)
        {
            firstPtr = firstPtr->next;
        }
        firstPtr->next = nullptr;
        return;
    }
    Node *secondPtr = loopPoint;
    while (firstPtr->next != secondPtr->next)
    {
        firstPtr = firstPtr->next;
        secondPtr = secondPtr->next;
    }
    secondPtr->next = nullptr;
}
LinkedList::Node *LinkedList::loopPointDetect()
{
    Node *slowPtr;
    Node *fastPtr;
    slowPtr = fastPtr = head;
    while (fastPtr->next != nullptr && fastPtr->next->next != nullptr)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (slowPtr == fastPtr)
        {
            return slowPtr;
        }
    }
    return nullptr;
}

LinkedList::Node *LinkedList::findIntersection(LinkedList::Node *head, LinkedList::Node *head2)
{
    int l1 = 0;
    int l2 = 0;
    Node *tempHead = head;
    Node *tempHead2 = head2;
    while (tempHead != nullptr)
    {
        l1++;
        tempHead = tempHead->next;
    }
    while (tempHead2 != nullptr)
    {
        l2++;
        tempHead2 = tempHead2->next;
    }
    int diff;
    if (l1 < l2)
    {
        Node *temp = head;
        head = head2;
        head2 = temp;
        diff = l2 - l1;
    }
    else
    {
        diff = l1 - l2;
    }
    for (; diff > 0; diff--)
    {
        head = head->next;
    }
    while (head != head2)
    {
        head = head->next;
        head2 = head2->next;
    }
    return head;
}

int main(int argc, char **argv)
{
    LinkedList ll;
    ll.addHead(1);
    ll.addHead(2);
    ll.addHead(3);
    ll.print();
    cout << ll.size() << endl;
    ll.addTail(5);
    ll.print();
    cout << ll.size() << endl;
    LinkedList *ll2 = ll.copyReversed();
    ll2->print();
    LinkedList *ll3 = ll.copyList();
    ll3->print();
    return 0;
}