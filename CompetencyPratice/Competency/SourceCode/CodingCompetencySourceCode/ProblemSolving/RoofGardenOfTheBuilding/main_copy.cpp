/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 9/10/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int N = 6;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    vector<long long> index(N);
    long long cnt = 0;
    stack<pair<long long, int>> s;
    for (int i = N - 1; i >= 0; --i) {
        if (!s.empty()) {
            while (!s.empty() && s.top().first < H[i]) {
                s.pop();
            }
        }
        index[i] = s.empty() ? -1 : s.top().second;
        s.push(make_pair(H[i], i));
    }
    for (int i = 0; i < N; ++i) {
        if (index[i] != -1) {
            cnt += index[i] - i - 1;
        } else {
            cnt += N - i - 1;
        }
    }
    cout << cnt << endl;
    return 0;
}

