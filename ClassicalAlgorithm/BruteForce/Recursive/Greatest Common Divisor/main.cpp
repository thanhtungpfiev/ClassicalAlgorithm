/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 5/5/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    cout << gcd(270, 192) << endl;
    return 0;
}
