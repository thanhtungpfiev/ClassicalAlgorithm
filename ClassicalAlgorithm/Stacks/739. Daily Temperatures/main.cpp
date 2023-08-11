/*
 * File: main.cpp
 * Project: 739. Daily Temperatures
 * File Created: Thursday, 10th August 2023 9:58:40 am
 * Author: Dao Thanh Tung (MS/EDA101-XC) (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// class Solution
// {
// public:
//     vector<int> dailyTemperatures(vector<int> &temperatures)
//     {
//         vector<int> answers;
//         for (int i = 0; i < temperatures.size(); ++i)
//         {
//             int answer = 0;
//             int isWarmer = false;
//             for (int j = i + 1; j < temperatures.size(); ++j)
//             {
//                 if (temperatures[j] > temperatures[i])
//                 {
//                     answer = j - i;
//                     answers.push_back(answer);
//                     isWarmer = true;
//                     break;
//                 }
//             }
//             if (!isWarmer)
//             {
//                 answers.push_back(answer);
//             }
//         }
//         return answers;
//     }
// };

class Solution
{
public:
    typedef pair<int, int> TemperatureWithIndex;
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> answers(temperatures.size());
        stack<TemperatureWithIndex> st;
        st.push(make_pair(temperatures[0], 0));
        for (int i = 1; i < temperatures.size(); ++i)
        {
            while (!st.empty() && temperatures[i] > st.top().first)
            {
                TemperatureWithIndex temperatureWithIndex = st.top();
                answers[temperatureWithIndex.second] = i - temperatureWithIndex.second;
                st.pop();
            }
            st.push(make_pair(temperatures[i], i));
        }
        return answers;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = sl.dailyTemperatures(temperatures);
    for (auto e : result)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}