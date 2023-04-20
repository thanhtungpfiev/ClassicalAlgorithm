/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 8/20/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bruteforce(const vector<int>& v) {
    int result = 0;
    for (int i1 = 0; i1 < v.size(); i1++) {
        for (int i2 = 0; i2 < v.size(); i2++) {
            for (int i3 = 0; i3 < v.size(); i3++) {
                for (int i4 = 0; i4 < v.size(); i4++) {
                    if (v[i4] == 0) {
                        continue;
                    }
                    for (int i5 = 0; i5 < v.size(); i5++) {
                        double sum = (v[i1] * v[i2] + v[i3]) * 1.0 / v[i4] - v[i5];
                        for (int i6 = 0; i6 < v.size(); i6++) {
                            if (v[i6] == sum) {
//                                cout << i1 << " " << i2 << " " << i3 << " " << i4 << " " << i5 << " " << i6 << endl;
                                cout << v[i1] << " " << v[i2] << " " << v[i3] << " " << v[i4] << " " << v[i5] << " " << v[i6] << endl;
                                result++;
                            }
                        }
                    }
                }
            }
        }
    }
    return result;
}

int searching(const vector<int>& v) {
    int result = 0;
    vector<int> v1;
    vector<int> v2;
    for (int i1 = 0; i1 < v.size(); ++i1) {
        for (int i2 = 0; i2 < v.size(); ++i2) {
            for (int i3 = 0; i3 < v.size(); ++i3) {
                v1.push_back(v[i1] * v[i2] + v[i3]);
                if (v[i3] != 0) {
                    v2.push_back((v[i1] + v[i2]) * v[i3]);
                }
            }
        }
    }
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    for (int i = 0; i < v1.size(); i++) {
        auto lo = lower_bound(v2.begin(), v2.end(), v1[i]);
        auto hi = upper_bound(v2.begin(), v2.end(), v1[i]);
        result += hi - lo;
    }
    return result;
}

int main()
{
    int N = 1;
    cin >> N;
    int temp = 0;
    vector<int> v;
    for (int i = 0; i < N; ++i) {
        cin >> temp;
        v.push_back(temp);
    }
    cout << searching(v) << endl;
    return 0;
}
