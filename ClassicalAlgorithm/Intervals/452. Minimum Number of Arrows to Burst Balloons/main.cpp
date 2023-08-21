/*
 * File: main.cpp
 * Project: 452. Minimum Number of Arrows to Burst Balloons
 * File Created: Monday, 14th August 2023 12:07:31 pm
 * Author: Dao Thanh Tung (MS/EDA101-XC) (thanhtungpfiev@gmail.com)
 * -----
 */
 #include <iostream>
 #include <vector>
 #include <algorithm>

 using namespace std;

 class Solution {
public:
    static bool compareX(vector<int>& point1, vector<int>& point2) {
        return point1[1] < point2[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        int result = 1;
        sort(points.begin(), points.end(), compareX);
        int k = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] <= k) {
                continue;
            } else {
                k = points[i][1];
                result++;
            }
        }

        return result;
    }
};

 int main(int argc, char **argv)
 {
     Solution sl;
     vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
     cout << sl.findMinArrowShots(points) << endl;
     return 0;
 }