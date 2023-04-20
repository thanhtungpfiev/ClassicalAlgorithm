/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 9/4/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <vector>

using namespace std;
const int NUM_OF_COLORS = 10;

int main()
{
    int N;
    cin >>N;
    vector<vector<int>> arr(N, vector<int>(N));
    string input;
    for (int i = 0; i < N; ++i) {
        cin >> input;
        for (int j = 0; j < N; ++j) {
            arr[i][j] = input[j] - '0';
        }
    }

    vector<bool> valid(NUM_OF_COLORS, true);

    for (int color = 1; color < NUM_OF_COLORS; ++color) {
        int xmin = N, ymin = N, xmax = -1, ymax = -1;
        for(int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (arr[i][j] == color) {
                    if (i < xmin) xmin = i;
                    if (i > xmax) xmax = i;
                    if (j < ymin) ymin = j;
                    if (j > ymax) ymax = j;
                }
            }
        }

        if (xmin == N) {
            valid[color] = false;
        }

        for (int i = xmin; i <= xmax; ++i) {
            for (int j = ymin; j <= ymax; ++j) {
                if (arr[i][j] != color) {
                    valid[arr[i][j]] = false;
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i < NUM_OF_COLORS; ++i) {
        if (valid[i] == true) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
