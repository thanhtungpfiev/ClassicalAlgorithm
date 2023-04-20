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
using namespace std;

#define MAX_PROJECT (15)
#define MAX_DATE (300)
typedef struct{
    int start_date; // Start date
    int end_date; // End date
}DATA;

int     N; // Number of projects
DATA    project_info[MAX_PROJECT]; // Project Infomation
bool		selected[MAX_PROJECT];
bool		mark[MAX_DATE + 1];

void Data_Input(void) {
    cin >> N; // Input of number of projects
    // Input of project information
    for (int i = 0; i<N; i++) {
        cin >> project_info[i].start_date >> project_info[i].end_date;
    }
}

void reset() {
    for (int i = 0; i < MAX_DATE; ++i) {
        mark[i] = false;
    }
}

bool assign(int index) {
    for (int i = project_info[index].start_date; i <= project_info[index].end_date; ++i) {
        if (mark[i]) {
            return false;
        }
        mark[i] = true;
    }
    return true;
}

int calculate() {
    int result = 0;

    reset();

    for (int i = 0; i < N; ++i) {
        if (selected[i]) {
            if (!assign(i)) {
                return -1;
            }
            ++result;
        }
    }
    return result;
}

void gen(int step, int& sol) {
    if (step == N) {
        int value = calculate();
        if (value > sol) {
            sol = value;
        }
        return;
    }
    for (int i = 0; i < 2; ++i) {
        selected[step] = i == 1;
        gen(step + 1, sol);
    }
}

int main(void) {
    int sol = 0;
    Data_Input(); // Calling of input function
    gen(0, sol);
    cout << sol << endl; // Output of result
    return 0;
}
