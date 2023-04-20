/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 8/25/2021
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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int M;
    cin >> M;
    int n;
    cin >> n;
    vector<int> W(n + 1);
    vector<int> V(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> W[i];
        cin >> V[i];
    }

    vector<vector<int>> F(n + 1, vector<int>(M + 1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= M; ++j) {
            F[i][j] = F[i - 1][j];
            if ((W[i] <= j) && (F[i][j] < (V[i] + F[i - 1][j - W[i]]))) {
                F[i][j] = V[i] + F[i - 1][j - W[i]];
            }
        }
    }

    cout << F[n][M] << endl;

//    while (n > 0) {
//        if (F[n][M] != F[n - 1][M]) {
//            cout << n << " ";
//            M = M - W[n];
//        }
//        n--;
//    }
//    cout << endl;
    return 0;
}
