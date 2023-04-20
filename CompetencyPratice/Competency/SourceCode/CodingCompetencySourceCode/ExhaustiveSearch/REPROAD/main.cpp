/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 8/5/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
#include <list>

using namespace std;

bool isCanBePrepaired(vector<int> v, int i, int j, int K) {
    int count = 0;
    for (int k = i; k <= j; ++k) {
        if (v[k] == 0) {
            ++count;
        }
    }
    if (count > K) {
        return false;
    }
    return true;
}

int bruteForce(vector<int> v, int K) {
    int result = 0;
    for (int i = 0; i < v.size() - 1; ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            if ((j - i + 1 > result) && isCanBePrepaired(v, i, j, K)) {
                result = j - i + 1;
            }
        }
    }
    return result;
}

int stackSolve(vector<int> v, int K) {
    int result = -1;
    list<int> q;
    int len = 0;
    int cost = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 0) {
            if (cost < K) {
                cost++;
                len++;
            } else {
                len = i - q.front();
                q.pop_front();
            }
            q.push_back(i);
        }
        else {
            len++;
        }
        result = max(result, len);
    }
    return result;
}

int main()
{
    int T;
    cin >> T;
    while (T --> 0) {
        int N, K;
        cin >> N >> K;
        vector<int> v(N);
        for (int i = 0; i < N; ++i) {
            cin >> v[i];
        }
        cout << stackSolve(v, K) << endl;
    }
    return 0;
}
