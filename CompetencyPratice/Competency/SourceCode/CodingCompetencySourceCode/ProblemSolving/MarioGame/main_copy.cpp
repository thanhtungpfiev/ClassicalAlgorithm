/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 9/7/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;

void genConfig(vector<int>& arr, int i)
{
    if (i == arr.size()) {
        v.push_back(arr);
        return;
    }
    for (int v = 0; v < 2; ++v) {
        arr[i] = v;
        genConfig(arr, i + 1);
    }
}

int calculate(const vector<int>& arr, const vector<int>& P)
{
    int value = 0;
    bool isOdd = true;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == 1) {
            if (isOdd) {
                value += P[i];
            } else {
                value -= P[i];
            }
            isOdd = !isOdd;
        }
    }
    return value;
}

int main()
{
    int N = 8;
    cin >> N;

    vector<int> P(N);
    for (int i = 0; i < N; i++){
        cin >> P[i];
    }

    vector<int> arr(N);
    genConfig(arr, 0);
    int maxVal = 0;
    for (int i = 0; i < v.size(); ++i) {
        vector<int> temp = v[i];
        int value = calculate(temp, P);
        if (value > maxVal) {
            maxVal = value;
        }
    }
    cout << maxVal << endl;

    return 0;
}
