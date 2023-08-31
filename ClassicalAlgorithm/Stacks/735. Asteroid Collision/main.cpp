/*
 * File: main.cpp
 * Project: 735. Asteroid Collision
 * File Created: Thursday, 31st August 2023 11:11:00 am
 * Author: Dao Thanh Tung (MS/EDA101-XC) (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        stack<int> st;
        for (auto e : asteroids) {
            bool isPush = true;
            while (!st.empty()) {
                if ((e > 0 && st.top() > 0) || (e < 0 && st.top() < 0) || (e > 0 && st.top() < 0)) {
                    st.push(e);
                    break;
                } else {
                    if (abs(e) < abs(st.top())) {
                        break;
                    } else if (abs(e) > abs(st.top())) {
                        st.pop();
                    } else {
                        isPush = false;
                        st.pop();
                        break;
                    }
                }
            }
            if (st.empty() && isPush) {
                st.push(e);
            }
        }
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}