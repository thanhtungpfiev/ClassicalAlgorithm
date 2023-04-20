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
#include <climits>

using namespace std;

int main()
{
    int N = 6;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    H.push_back(INT_MAX);
    long long cnt = 0;
    stack<int> s;
    s.push(0);
    for (int i = 1; i <= N; ++i) {
        if (!s.empty() && H[i] >= H[s.top()]) {
            while (!s.empty() && H[i] >= H[s.top()]) {
                cnt += i - s.top() - 1;
                s.pop();
            }
        }
        s.push(i);
    }

    cout << cnt << endl;
    return 0;
}

