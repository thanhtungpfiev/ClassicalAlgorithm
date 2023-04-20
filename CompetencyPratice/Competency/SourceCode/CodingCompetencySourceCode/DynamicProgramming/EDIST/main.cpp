/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 8/26/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int min3Numbers(int a, int b, int c)
{
    int result = a;
    result = min(result, b);
    result = min(result, c);
    return result;
}

int main()
{
    int T;
    cin >> T;
    while (T --> 0) {
        std::string X;
        cin >> X;
        std::string Y;
        cin >> Y;
        int n = X.length();
        int m = Y.length();
        vector<vector<int>> F(n + 1, vector<int>(m + 1));

        for (int i = 0; i <= n; ++i) F[i][0] = i;
        for (int j = 0; j <= m; ++j) F[0][j] = j;

        // build result table
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (X[i - 1] == Y[j - 1]) {
                    F[i][j] = F[i - 1][j -1];
                } else {
                    F[i][j] = min3Numbers(F[i][j - 1], F[i - 1][j - 1], F[i - 1][j]) + 1;
                }
            }
        }

        cout << F[n][m] << endl;

        // trace
        int i = n, j = m;
        while ((i >= 0) && (j >= 0)) {
            if (X[i - 1] == Y[j - 1]) { //Hai ký tự cuối của xâu giống nhau
                --i; --j;
            } else {
                if (F[i][j] == F[i][j - 1] + 1) { //Phép chèn
                    cout << "Insert(" << i << "," << Y[j - 1] << ")" << endl;
                    --j;
                } else if (F[i][j] == F[i - 1][j - 1] + 1) { //Phép thay thế
                    cout << "Replace(" << i  << "," << Y[j - 1] << ")" << endl;
                    --i; --j;
                } else {  //Phép xóa
                    cout << "Delete(" << i << "," << X[i - 1] << ")" << endl;
                    --i;
                }
            }
        }
    }

}
