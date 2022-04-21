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

using namespace std;

int main()
{
    long long n = 3;
    cin >> n;
    while (true) {
        cout << n << " ";
        if (n == 1) {
            break;
        }
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = n * 3 + 1;
        }
    }
    cout << endl;
    return 0;
}
