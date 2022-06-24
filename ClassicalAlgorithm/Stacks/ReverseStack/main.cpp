#include <iostream>
#include <stack>

using namespace std;

template <typename T>
void insertAtBottom(stack<T> &stk, T value)
{
    if (stk.empty())
        stk.push(value);
    else
    {
        T out = stk.top();
        stk.pop();
        insertAtBottom(stk, value);
        stk.push(out);
    }
}

template <typename T>
void reverseStack(stack<T> &stk)
{
    if (stk.empty())
        return;
    else
    {
        T value = stk.top();
        stk.pop();
        reverseStack(stk);
        insertAtBottom(stk, value);
    }
}

int main(int argc, char **argv)
{
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    reverseStack(stk);
    return 0;
}