/**
 * author thanhtung thanhtungpfiev@gmail.com
 *
 * date 30 - 4 - 2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int T = 5;
    cin >> T;
    while (T --> 0) {
        int n = 2;
        cin >> n;
        string BobStr = "", AliceStr = "";
        cin >> BobStr >> AliceStr;
        string BobStrRv = BobStr;
        reverse(BobStrRv.begin(), BobStrRv.end());
        if (BobStr > BobStrRv) {
            BobStr = BobStrRv;
        }
        sort(AliceStr.begin(), AliceStr.end());
        vector<string> AliceStrs;
        if (AliceStr >= BobStr) {
            reverse(AliceStr.begin(), AliceStr.end());
            AliceStr.pop_back();
        } else {
            do {
                if (AliceStr < BobStr) {
                    AliceStrs.push_back(AliceStr);
                }
            } while (next_permutation(AliceStr.begin(), AliceStr.end()));
            sort(AliceStrs.begin(), AliceStrs.end());
            AliceStr = AliceStrs[AliceStrs.size() - 1];
        }
        cout << AliceStr << endl;
    }
    return 0;
}
