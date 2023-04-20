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
#include <queue>
#include <climits>

using namespace std;

struct Candidate
{
    int index;
    int value;
    Candidate(int index1, int value1) {
        index = index1;
        value = value1;
    }
};

struct CompareCandidateMaxHeap
{
    bool operator()(const Candidate& a, const Candidate& b) {
        if (a.value == b.value) {
            return a.index < b.index;
        }
        return a.value < b.value;
    }
};

struct CompareCandidateMinHeap
{
    bool operator()(const Candidate& a, const Candidate& b) {
        if (a.value == b.value) {
            return a.index > b.index;
        }
        return a.value > b.value;
    }
};


int main()
{
    int N = 5;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    int i = 0;
    int iMax = i;
    int j = N - 1;
    int jMax = j;
    int minValue = abs(A[iMax] + A[jMax]);
    while (i < j) {
        if (abs(A[i] + A[j]) < minValue) {
            minValue = abs(A[i] + A[j]);
            iMax = i;
            jMax = j;
        }
        if (A[i] + A[j] > 0) {
            --j;
        } else if (A[i] + A[j] < 0) {
            ++i;
        } else {
            break;
        }
    }
    cout << iMax << " " << jMax << endl;
    return 0;
}
