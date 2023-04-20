/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 9/12/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N = 6;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }
    vector<int> F(N);
    F[0] = P[0];
    F[1] = P[0] + P[1];
    F[2] = P[2] + max(P[0], P[1]);
    for (int i = 3; i < N; ++i) {
        F[i] = P[i] + max(P[i - 1] + F[i - 3], F[i - 2]);
    }
    cout << F[N - 1] << endl;
    return 0;
}
