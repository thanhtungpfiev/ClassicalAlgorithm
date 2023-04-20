/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 8/18/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

void copyArray(vector<int>& A, int iBegin, int iEnd, vector<int>& B)
{
    for (int i = iBegin; i < iEnd; ++i) {
        B[i] = A[i];
    }
}

void topdownMerge(vector<int>& A, int iBegin, int iMiddle, int iEnd, vector<int>& B)
{
    int i = iBegin, j = iMiddle;

    for (int k = iBegin; k < iEnd; ++k) {
        if (i < iMiddle && (j >= iEnd || A[i] < A[j])) {
            B[k] = A[i];
            ++i;
        } else {
            B[k] = A[j];
            ++j;
        }
    }
}

void topdownSplitMerge(vector<int>& B, int iBegin, int iEnd, vector<int>& A)
{
    if (iEnd - iBegin <= 1) return; // nếu size là 1 thì dãy đã được sắp xếp
    int iMiddle = (iEnd + iBegin) / 2; //chia dãy ra làm hai
    topdownSplitMerge(A, iBegin, iMiddle, B); //  xắp xếp dãy bên trái của dãy B, do dó dãy A biến thành dãy trung gian
    topdownSplitMerge(A, iMiddle, iEnd, B); //  xắp xếp dãy bên phải của dãy B, do dó dãy A biến thành dãy trung gian

    topdownMerge(B, iBegin, iMiddle, iEnd, A); //hợp nhất hai dãy đã được sắp xếp nằm trên B thành một dãy nằm trên A
}

void topdownMergeSort(vector<int>& A, vector<int>& B, int n)
{
    copyArray(A, 0, n, B);
    topdownSplitMerge(B, 0, n, A); //sort data from B[] to A[]
}

int main()
{
    cout << "Hello World!" << endl;
    vector<int> A = {1, 3, 2, 5, 4};
    vector<int> B(A.size());
    topdownMergeSort(A, B, A.size());
    for (auto it : A) {
        cout << it << " ";
    }
    cout << endl;

    vector<int> A2 = {1, 3, 2, 5, 4, 7, 1 , 5};
    vector<int> B2(A2.size());
    topdownMergeSort(A2, B2, A2.size());
    for (auto it : A2) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
