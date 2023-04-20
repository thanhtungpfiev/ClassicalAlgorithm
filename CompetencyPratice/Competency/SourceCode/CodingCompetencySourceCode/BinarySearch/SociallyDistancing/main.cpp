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
#include <algorithm>
#include <climits>

using namespace std;

bool check(const vector<int>& v, int s, int D)
{
    bool result = false;
    int temp = 1;
    int cur = v[0];
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] >= cur + D) {
            cur = v[i];
            temp++;
            if (temp == s) {
                result = true;
                break;
            }
        }
    }
    return result;
}

//int bruteforce(const vector<int>& v, int s)
//{
//    int ret = INT_MIN;
//    for (int D = 1; D <= v[v.size() - 1]; ++D) {
//        if (check(v, s, D)) {
//            ret = D;
//        }
//    }
//    return ret;
//}

int binarySearch(const vector<int>& v, int s)
{
    int ret = 0;
    int l = 0, r = v[v.size() - 1] - v[0];
    while (l < r - 1) {
        int D = l + (r - l) / 2;
        if (check(v, s, D)) {
            l = D;
        } else {
            r = D;
        }
    }
    for (int D = r; D >= l; D--) {
        if (check(v, s, D)) {
            ret = D;
            break;
        }
    }
    return ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int T;
    cin >> T;
    while (T --> 0) {
        int N;
        cin >> N;
        int s;
        cin >> s;
        vector<int> v(N);
        for (int i = 0; i < N; ++i) {
            cin >> v[i];
        }
        std::sort(v.begin(), v.end());
        cout << binarySearch(v, s) << endl;
    }
    return 0;
}
