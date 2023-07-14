/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 4/21/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bruteforce(int n, vector<int>& permutation, vector<bool>& chosen)
{
    if (permutation.size() == n) {
        for (const auto e : permutation) {
            cout << e << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!chosen[i]) {
            chosen[i] = true;
            permutation.push_back(i);
            bruteforce(n, permutation, chosen);
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

void usingSTL(int n, vector<int>& permutation)
{
    for (int i = 1; i <= n; ++i) {
        permutation.push_back(i);
    }
    do {
        for (const auto e : permutation) {
            cout << e << " ";
        }
        cout << endl;
    } while (next_permutation(permutation.begin(), permutation.end()));
}

int main()
{
    int n = 3;
    cin >> n;
    vector<int> permutation;
    vector<bool> chosen(n + 1);
    bruteforce(n, permutation, chosen);
    cout << "======================\n";
    vector<int> permutation2;
    usingSTL(n, permutation2);
    return 0;
}
