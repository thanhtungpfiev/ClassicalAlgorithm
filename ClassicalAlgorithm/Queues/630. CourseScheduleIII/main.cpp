/*
 * File: main.cpp
 * Project: CourseScheduleIII
 * File Created: Thursday, 23rd June 2022 11:44:11 am
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
    int scheduleCourse(vector<vector<int>> &courses)
    {
        sort(courses.begin(), courses.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });
        priority_queue<vector<int>> pq;
        int totalCourse = 0;
        for (int i = 0; i < courses.size(); ++i)
        {
            int duration = courses[i][0];
            int deadline = courses[i][1];

            if (duration + totalCourse <= deadline)
            {
                pq.push(courses[i]);
                totalCourse += duration;
            }
            else
            {
                if (!pq.empty())
                {
                    auto course = pq.top();
                    if (duration < course[0])
                    {
                        pq.pop();
                        totalCourse -= course[0];
                        pq.push(courses[i]);
                        totalCourse += duration;
                    }
                }
            }
        }
        return pq.size();
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    vector<vector<int>> courses = {{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
    cout << sl.scheduleCourse(courses) << endl;
    vector<vector<int>> courses = {{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
    courses = [[1,2]]
    vector<vector<int>> courses = {{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
    courses = [[3,2],[4,3]]
    return 0;
}