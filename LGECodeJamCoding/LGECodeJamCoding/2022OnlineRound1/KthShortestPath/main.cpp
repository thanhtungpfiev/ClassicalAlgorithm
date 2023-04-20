/**
 * author thanhtung thanhtungpfiev@gmail.com
 *
 * date 26 - 3 - 2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
 *
 */
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int convertStrToNumber(string& s)
{
    int result = 0;
    stringstream convert(s);
    convert >> result;
    return result;
}

void buildDPfromSrcDest(const int& src, const int& dest, const int& L)
{
    if (L == 2) {
        vector<int> dp(100, -1);
        dp[dest] = 1;
        int src_hang_chuc = src / 10;
        int src_hang_don_vi = dest % 10;
        int dest_hang_chuc = dest / 10;
        int dest_hang_don_vi = dest % 10;

        while ((dest_hang_chuc != src_hang_chuc) && (dest_hang_don_vi != src_hang_don_vi)) {
            if (dest)
        }
    }
}

int main()
{
    int T = 0;
    cin >> T;
    while (T --> 0) {
        int L = 0, K = 0;
        cin >> L >> K;
        string srcStr = "", destStr = "";
        cin >> srcStr >> destStr;
        int src = convertStrToNumber(srcStr);
        int dest = convertStrToNumber(destStr);
        if (src > dest) {
            swap(src, dest);
        }
        buildDPfromSrcDest(src, dest, L);
    }
    return 0;
}
