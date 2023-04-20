/**
 * author thanhtung thanhtungpfiev@gmail.com
 *
 * date 26 - 3 - 2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
 *
 */
#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> iPair;

struct Node
{
    int value = 0;
    Node* parent = nullptr;
};

// Function to find the smallest divisor
int smallestDivisor(int n)
{
    // if divisible by 2
    if (n % 2 == 0)
        return 2;

    // iterate from 3 to sqrt(n)
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return i;
    }

    return n;
}

int main()
{
    int T = 0;
    cin >> T;
    while (T --> 0) {
        int N = 0;
        cin >> N;
        vector<int> v;
        for (int i = 0; i < N; ++i) {
            int temp = 0;
            cin >> temp;
            v.push_back(temp);
        }
        int best = INT_MAX;
        for (int cnt = 0; cnt < v.size(); cnt++) {
            int last = v[v.size() - 1];
            v.pop_back();
            vector<vector<int>> g;
            for (int i = 0; i < v.size(); ++i) {
                vector<int> v1;
                int temp = v[i];
                if (temp == 1) {
                    v1.push_back(1);
                    g.push_back(v1);
                } else {
                    while (temp != 1) {
                        v1.push_back(temp);
                        int smallestD = smallestDivisor(temp);
                        temp = temp / smallestD;
                    }
                    v1.push_back(1);
                    g.push_back(v1);
                }
            }

            int total = 0;
            for (int i = 0; i < g.size() - 1; ++i) {
                for (int j = i + 1; j < g.size(); ++j) {
                    vector<int> arr1 = g[i];
                    vector<int> arr2 = g[j];
                    vector<int> arr(arr1.size() + arr2.size());
                    reverse(arr1.begin(), arr1.end());
                    reverse(arr2.begin(), arr2.end());
                    vector<int>::iterator it = set_intersection(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), arr.begin());
                    int root = *(it - 1);
                    int sum = 0;
                    for (int i = arr1.size() - 1; i >= 0; --i) {
                        if (arr1[i] == root) {
                            break;
                        }
                        sum += arr1[i] / arr1[i - 1];
                    }
                    for (int i = arr2.size() - 1; i >= 0; --i) {
                        if (arr2[i] == root) {
                            break;
                        }
                        sum += arr2[i] / arr2[i - 1];
                    }
                    total += sum;
                }
            }
            best = min(best, total);
            v.insert(v.begin(), last);
        }
        cout << best << endl;


    }
    return 0;
}
