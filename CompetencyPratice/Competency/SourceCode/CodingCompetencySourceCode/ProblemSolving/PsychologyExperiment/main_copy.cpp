/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 9/14/2021
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

int main()
{
    int N = 5;
    cin >> N;
    vector<int> A(N);
//    A = {-102, -58, 59, 78, 101};
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    int minValue = INT_MAX;
    int iMax = 0, jMax = 1;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (abs(A[i] + A[j]) < minValue) {
                minValue = abs(A[i] + A[j]);
                iMax = i;
                jMax = j;
            }
        }
    }
    cout << iMax << " " << jMax << endl;
    return 0;
}
