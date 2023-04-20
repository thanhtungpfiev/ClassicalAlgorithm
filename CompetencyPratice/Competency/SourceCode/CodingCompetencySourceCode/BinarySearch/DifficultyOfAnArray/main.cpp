/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 8/21/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;
bool check(const vector<int>& v, int K, int D)
{
    bool result = true;
    int temp = 0;
    for (int i = 1; i < v.size(); i++) {
        temp += (v[i] - v[i - 1] - 1) / D;
    }
    if (temp > K) result = false;
    return result;
}

// brutforce
//int solve(const vector<int>& v, int N, int K)
//{
//    int ret = INT_MAX;
//    for (int D = v[N - 1]; D >= 1; D--) {
//        if (check(v, K, D)) {
//            ret = D;
//        }
//    }
//    return ret;
//}

// binary search
int solve(const vector<int>& v, int N, int K)
{
    int ret = INT_MAX;
    int l = 0, r = v[N - 1] - v[0];
    while (l < r - 1) {
        int D = l + (r - l) / 2;
        if (check(v, K, D)) {
            r = D;
        } else {
            l = D;
        }
    }
    ret = r;
    return ret;
}

int main()
{
    int T;
    cin >> T;
    int caseth = 1;
    while (T --> 0) {
        int N;
        cin >> N;
        int K;
        cin >> K;
        vector<int> v(N);
        for (int i = 0; i < N; ++i) {
            cin >> v[i];
        }
        int result = solve(v, N, K);
        cout << "Case #" << caseth << ": " << result << endl;
        caseth++;
    }

    return 0;
}
