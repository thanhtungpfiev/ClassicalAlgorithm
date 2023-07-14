/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 5/27/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;
        while (num) {
            if (num % 2) {
                num -= 1;
            } else {
                num /= 2;
            }
            count++;
        }
        return count;
    }
};

int main()
{
    int num = 14;
    Solution sl;
    cout << sl.numberOfSteps(num) << endl;
    num = 8;
    cout << sl.numberOfSteps(num) << endl;
    num = 123;
    cout << sl.numberOfSteps(num) << endl;
    return 0;
}
