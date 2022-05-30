/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 5/30/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        return dividend / divisor;
    }

    /*
     * The key observation is that the quotient of a division is just the number of times that we can subtract the divisor from the dividend without making it negative.

Suppose dividend = 15 and divisor = 3, 15 - 3 > 0. We now try to subtract more by shifting 3 to the left by 1 bit (6). Since 15 - 6 > 0, shift 6 again to 12.
Now 15 - 12 > 0, shift 12 again to 24, which is larger than 15. So we can at most subtract 12 from 15. Since 12 is obtained by shifting 3 to left twice,
it is 1 << 2 = 4 times of 3. We add 4 to an answer variable (initialized to be 0). The above process is like 15 = 3 * 4 + 3. We now get part of the
quotient (4), with a remaining dividend 3.

Then we repeat the above process by subtracting divisor = 3 from the remaining dividend = 3 and obtain 0. We are done. In this case, no shift happens.
We simply add 1 << 0 = 1 to the answer variable.
     */
    int divide2(int A, int B) {
        if (A == INT_MIN && B == -1) return INT_MAX;
        long a = abs(A), b = abs(B), res = 0, x = 0;
        while (a - b >= 0) {
            for (x = 0; a - (b << x << 1) >= 0; x++);
            res += 1 << x;
            a -= b << x;
        }
        return (A > 0) == (B > 0) ? res : -res;
    }
};

int main()
{
    Solution sl;
    cout << sl.divide(10, 3) << endl;
    cout << sl.divide(7, -3) << endl;
    cout << sl.divide2(10, 3) << endl;
    cout << sl.divide2(7, -3) << endl;
    return 0;
}
