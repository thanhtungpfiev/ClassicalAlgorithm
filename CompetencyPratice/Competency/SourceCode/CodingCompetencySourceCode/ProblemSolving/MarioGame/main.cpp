/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 9/7/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

bool findingDescendingArray(int& pos, int&posMax, int& posMin, vector<int>& P)
{
    if (pos >= P.size()) {
        return false;
    }
    while (P[pos] < P[pos + 1]) ++pos;
    posMax = pos;
    while (P[pos] > P[pos + 1]) ++pos;
    posMin = pos;
    ++pos;
    return true;
}

int main()
{
    int N = 8;
    cin >> N;

    vector<int> P(N + 1);
    for (int i = 0; i < N; i++){
        cin >> P[i];
    }

    int pos = 0, posMax = 0, posMin = 0;
    int maxVal = 0;
    while (findingDescendingArray(pos, posMax, posMin, P)) {
           maxVal += P[posMax] - P[posMin];
    }

    cout << maxVal << endl;

    return 0;
}
