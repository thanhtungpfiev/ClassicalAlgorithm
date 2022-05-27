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
#include <climits>

using namespace std;

void printArr(const vector<int>& arr)
{
    for (auto it : arr) {
        cout << it << " ";
    }
    cout << endl;
}

void build(const vector<int>& arr, vector<int>& L, vector<int>& T)
{
    L[arr.size() - 1] = 1;
    for (int i = arr.size() - 2; i >= 0; --i) {
        int jmax = arr.size() - 1;
        for (int j = i + 1; j <= arr.size() - 1; ++j) {
            if ((arr[j] > arr[i]) && (L[j] > L[jmax])) {
                jmax = j;
            }
        }
        L[i] = L[jmax] + 1;
        T[i] = jmax;
    }
}

int trace(const vector<int>& A, const vector<int>& T)
{
    int result = 0;
    int i = T[0];
    while (i != T.size()) {
        i = T[i];
        result++;
    }
    return result;
}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for (int i = 0; i < nums.size(); ++i) {
            int curr = nums[i];
            auto it = lower_bound(lis.begin(), lis.end(), curr);
            if (it == lis.end()) {
                lis.push_back(curr);
            } else {
                *it = curr;
            }
        }
        for (const auto &e : lis) {
            cout << e << " ";
        }
        return lis.size();
    }
};

int main()
{
//    int N;
//    cin >> N;
//    vector<int> A(N);
//    for (int i = 0; i < N; ++i) {
//        cin >> A[i];
//    }
//    A.insert(A.begin(), INT_MIN);
//    A.push_back(INT_MAX);
//    vector<int> L(A.size());
//    vector<int> T(A.size() - 1);
//    build(A, L, T);
//    cout << trace(A, T) << endl;

    vector<int> v = {10,9,2,5,3,7,101,18};
    Solution sl;
    cout << sl.lengthOfLIS(v) << endl;
}
