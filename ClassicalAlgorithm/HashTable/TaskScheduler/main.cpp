/*
 * File: main.cpp
 * Project: TaskScheduler
 * File Created: Tuesday, 23rd August 2022 1:31:41 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int result = 0;
        vector<int> freq_tasks(26, 0);
        for (int i = 0; i < tasks.size(); ++i)
        {
            freq_tasks[tasks[i] - 'A']++;
        }
        int max_freq_tasks = *max_element(freq_tasks.begin(), freq_tasks.end());
        int number_of_max_freq_tasks = count(freq_tasks.begin(), freq_tasks.end(), max_freq_tasks);
        int part_count = max_freq_tasks - 1;
        int empty_slots = part_count * (n - (number_of_max_freq_tasks - 1));
        int available_tasks = tasks.size() - max_freq_tasks * number_of_max_freq_tasks;
        int idles = max(0, empty_slots - available_tasks);
        result = tasks.size() + idles;
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: tasks = ["A","A","A","B","B","B"], n = 2
    // Output: 8
    // Explanation:
    // A -> B -> idle -> A -> B -> idle -> A -> B
    // There is at least 2 units of time between any two same tasks.

    // Input: tasks = ["A","A","A","B","B","B"], n = 0
    // Output: 6
    // Explanation: On this case any permutation of size 6 would work since n = 0.
    // ["A","A","A","B","B","B"]
    // ["A","B","A","B","A","B"]
    // ["B","B","B","A","A","A"]
    // ...
    // And so on.

    // Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
    // Output: 16
    // Explanation:
    // One possible solution is
    // A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
    return 0;
}