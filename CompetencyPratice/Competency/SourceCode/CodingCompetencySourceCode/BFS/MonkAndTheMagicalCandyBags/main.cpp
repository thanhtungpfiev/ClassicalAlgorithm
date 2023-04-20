/**********************************************************************
 *
 * author tung.dao tung.dao@lge.com
 *
 * date 10/3/2021
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T --> 0) {
        int N, K;
        cin >> N >> K;
        priority_queue<long long> q;
        for (int n = 1; n <= N; ++n) {
            long long candy;
            cin >> candy;
            q.push(candy);
        }
        long long result = 0;
        for (int k = 1; k <= K; ++k) {
            long long candy = q.top();
            q.pop();
            result += candy;
            candy = static_cast<long long>(candy / 2);
            q.push(candy);
        }
        cout << result << endl;
    }
    return 0;
}
