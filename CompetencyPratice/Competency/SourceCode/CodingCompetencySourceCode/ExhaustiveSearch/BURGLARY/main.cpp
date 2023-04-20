/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 8/15/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/* Cach 1: Liet ke day nhi phan

std::vector<std::vector<int>> b;

void printConfig(const vector<int> & v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void tryConfig(int i, int n, vector<int>& c) {
    for (int v = 0; v <= 1; ++ v) {
        c[i] = v;
        if (i == n - 1) {
            b.push_back(c);
        } else {
            tryConfig(i + 1, n, c);
        }
    }
}

pair<int, int> solve(const vector<unsigned long>& arr, unsigned long D) {
    // Sinh 1 list cac day nhi phan voi 1 la chon va 0 la khong chon
    pair<int, int> result;
    int n = arr.size();
    std::vector<int> c(n, 0);
    b.clear();
    tryConfig(0, n, c);

    int cnt = 0;
    int k = 0;
    for (int i = 0; i < b.size(); ++i) {
        std::vector<int> c = b[i];
        unsigned long sum = 0;
        for (int j = 0; j < c.size(); ++j) {
            if (c[j]) {
                sum += arr[j];
            }
        }
        if (sum == D) {
            if (k != std::count(c.begin(), c.end(), 1)) {
                k = std::count(c.begin(), c.end(), 1);
                cnt++;
            }
            if (cnt > 1) {
                break;
            }
        }
    }
    result.first = cnt;
    result.second = k;
    return result;
}

int main()
{
    int T;
    cin >> T;
    int caseth = 0;
    while (T --> 0) {
        int N;
        cin >> N;
        unsigned long D;
        cin >> D;
        vector<unsigned long> arr(N);
        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
        }
        pair<int, int> result = solve(arr, D);
        caseth++;
        if (result.first == 0) {
            cout << "Case #" << caseth << ": IMPOSSIBLE" << endl;
        } else if (result.first == 1) {
            cout << "Case #" << caseth << ": " << result.second << endl;
        } else {
            cout << "Case #" << caseth << ": AMBIGIOUS" << endl;
        }
    }

    return 0;
}
*/

/* Cach 2: chia thanh 2 day con, liet ke to hop cua tung day con


vector< vector<int> > getAllSubsets(vector<int> set)
{
    vector< vector<int> > subset;
    vector<int> empty;
    subset.push_back( empty );

    for (int i = 0; i < set.size(); i++)
    {
        vector< vector<int> > subsetTemp = subset;

        for (int j = 0; j < subsetTemp.size(); j++)
            subsetTemp[j].push_back( set[i] );

        for (int j = 0; j < subsetTemp.size(); j++)
            subset.push_back( subsetTemp[j] );
    }
    return subset;
}

void printConfig(const vector<int> & v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {1, 2, 3};
    vector< vector<int> > subset = getAllSubsets(v);
    for (int i = 0; i < subset.size(); ++i) {
        vector<int> temp = subset[i];
        printConfig(temp);
    }
    return 0;
}
*/

/* Cach 3: dung day nhi phan de liet ke to hop
 */
std::vector<std::vector<int>> b;

void printConfig(const vector<int> & v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void printConfig(const vector<unsigned long> & v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void tryConfig(int i, int n, vector<int>& c) {
    for (int v = 0; v <= 1; ++ v) {
        c[i] = v;
        if (i == n - 1) {
            b.push_back(c);
        } else {
            tryConfig(i + 1, n, c);
        }
    }
}

map<unsigned long, int> generateMap(const vector<unsigned long>& arr) {
    // Sinh 1 list cac day nhi phan voi 1 la chon va 0 la khong chon
    map<unsigned long, int> result;
    int n = arr.size();
    std::vector<int> c1(n, 0);
    b.clear();
    tryConfig(0, n, c1);
    for (int i = 0; i < b.size(); ++i) {
        std::vector<int> c = b[i];
        unsigned long sum = 0;
        for (int j = 0; j < c.size(); ++j) {
            if (c[j]) {
                sum += arr[j];
            }
        }
        int cnt = std::count(c.begin(), c.end(), 1);
        if (sum != 0) {
            if (result[sum] != 0 && result[sum] != cnt) {
                result[sum] = -2;
            } else {
                result[sum] = cnt;
            }
        } else {
            if (cnt == 0) {
                result[sum] = 0;
            } else {
                result[sum] = -2;
            }
        }

    }

    return result;
}

int main()
{
    int T;
    cin >> T;
    int caseth = 0;
    while (T --> 0) {
        int N;
        cin >> N;
        unsigned long D;
        cin >> D;
        vector<unsigned long> arr1;
        vector<unsigned long> arr2;
        int temp = 0;
        for (int i = 0; i < N; ++i) {
            cin >> temp;
            if (i < N / 2) {
                arr1.push_back(temp);
            } else {
                arr2.push_back(temp);
            }
        }
        map<unsigned long, int> m1 = generateMap(arr1);
        map<unsigned long, int> m2 = generateMap(arr2);
        caseth++;
        unsigned long can = 0;
        int ans = -1;
        for (auto it : m1) {
            if (can == 2) {
                break;
            }
            unsigned long n = D - it.first;
            if (m2.count(n)) {
                if (it.second == -2 || m2[n] == -2) {
                    can = 2;
                    break;
                }
                int cur = it.second + m2[n];
                if (ans != -1 && ans != cur) {
                    can = 2;
                    break;
                }
                ans = cur;
                can = 1;
            }
        }
        if (can == 0) {
            cout << "Case #" << caseth << ": IMPOSSIBLE" << endl;
        } else if (can == 1) {
            cout << "Case #" << caseth << ": " << ans << endl;
        } else {
            cout << "Case #" << caseth << ": AMBIGIOUS" << endl;
        }
    }

    return 0;
}
