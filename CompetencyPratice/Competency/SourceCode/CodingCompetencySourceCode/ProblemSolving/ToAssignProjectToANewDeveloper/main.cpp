/**********************************************************************
 *
 * author tung.dao tung.dao@lge.com
 *
 * date 9/19/2021
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_PROJECT (15)
typedef struct{
    int start_date; // Start date
    int end_date; // End date
}DATA;

int     N; // Number of projects

bool compareProject(const DATA& a, const DATA& b) {
    return a.end_date < b.end_date;
}

int main(void) {
    int sol = 0;
    cin >> N; // Input of number of projects
    // Input of project information
    vector<DATA> project_info(N); // Project Infomation
    vector<int> selected(N);
    for (int i = 0; i<N; i++) {
        cin >> project_info[i].start_date >> project_info[i].end_date;
    }

    std::sort(project_info.begin(), project_info.end(), compareProject);

    int lastend = -1;
    for (int i = 0; i<N; i++) {
        if (lastend < project_info[i].start_date) {
            lastend = project_info[i].end_date;
            ++sol;
        }
    }
    cout << sol << endl; // Output of result
    return 0;
}
