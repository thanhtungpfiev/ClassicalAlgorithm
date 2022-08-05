/*
 * File: main.cpp
 * Project: MyCalendarI
 * File Created: Wednesday, 3rd August 2022 1:55:48 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MyCalendar
{
public:
    typedef pair<int, int> myPair;
    vector<myPair> m_v;
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        for (auto &e : m_v)
        {
            if (e.first < end && start < e.second)
            {
                return false;
            }
        }
        m_v.push_back(make_pair(start, end));
        return true;
    }
};

class MyCalendar
{
    map<int, int> books;

public:
    bool book(int s, int e)
    {
        auto next = books.lower_bound(s); // first element with key not go before k (i.e., either it is equivalent or goes after).
        if (next != books.end() && next->first < e)
            return false; // a existing book started within the new book (next)
        if (next != books.begin() && s < (--next)->second)
            return false; // new book started within a existing book (prev)
        books[s] = e;
        return true;
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    //     Input
    // ["MyCalendar", "book", "book", "book"]
    // [[], [10, 20], [15, 25], [20, 30]]
    // Output
    // [null, true, false, true]

    // Explanation
    // MyCalendar myCalendar = new MyCalendar();
    // myCalendar.book(10, 20); // return True
    // myCalendar.book(15, 25); // return False, It can not be booked because time 15 is already booked by another event.
    // myCalendar.book(20, 30); // return True, The event can be booked, as the first event takes every time less than 20, but not including 20.
    return 0;
}