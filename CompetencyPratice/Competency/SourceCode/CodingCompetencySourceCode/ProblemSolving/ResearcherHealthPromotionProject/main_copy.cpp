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

int caculate(const vector<int>& P, const vector<bool>& selected)
{
    int result = 0;
    for (int i = 0; i < P.size(); ++i) {
        if (selected[i]) {
            result += P[i];
        }
    }
    return result;
}

void gen(int step, int N, const vector<int>& P, vector<bool>& selected, int& maxVal)
{
    if (step == N) {
        if (selected[N - 1]) {
            int value = caculate(P, selected);
            if (value > maxVal) {
                maxVal = value;
            }
        }
    } else {
        if (step > 1 && selected[step - 1] && selected[step - 2]) {
            selected[step] = false;
            gen(step + 1, N, P, selected, maxVal);
        } else if (step > 0 && !selected[step - 1]) {
            selected[step] = true;
            gen(step + 1, N, P, selected, maxVal);
        } else {
            for (int i = 0; i < 2; ++i) {
                selected[step] = i == 1;
                gen(step + 1, N, P, selected, maxVal);
            }
        }
    }
}

int main()
{
    int N = 6;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }
    vector<bool> selected(N, false);
    int maxVal = 0;
    gen(0, N, P, selected, maxVal);
    cout << maxVal << endl;
    return 0;
}
