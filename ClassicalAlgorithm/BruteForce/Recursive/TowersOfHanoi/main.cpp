/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 5/26/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>

using namespace std;

void TowersOfHanoi(int n, char frompeg, char topeg, char auxpeg)
{
    // If only 1 disk, make the move and return
    if (n == 1) {
        cout << "Move disk 1 from " << frompeg << " to " << topeg << endl;
        return;
    }
    // Move top n - 1 disks from A to B, using C as auxiliary
    TowersOfHanoi(n - 1, frompeg, auxpeg, topeg);

    // Move remaining disks from A to C
    cout << "Move disk " << n << " from " << frompeg << " to " << topeg << endl;

    // Move n - 1 disks from B to C using A as auxiliary
    TowersOfHanoi(n - 1, auxpeg, topeg, frompeg);
}

int main()
{
    TowersOfHanoi(2, 'A', 'B', 'C');
    return 0;
}
