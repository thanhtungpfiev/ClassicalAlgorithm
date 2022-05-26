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

class Solution {
public:
    int hammingWeight(uint32_t n) {

        //initliaize the variable for count of 1
        unsigned int count = 0;

        //it will run the loop till pointer traverse the whole unsigned number
        while(n>0){

            //it will increase the count when it finds the 1 in the number by doing logical AND Opeartion
            count +=n & 1;

            // it will perform the right shift into the unsigned int number
            n>>=1;
        }
        return count;


    }
};

int main()
{
    uint32_t n = 00000000000000000000000000001011;
    Solution sl;
    cout << sl.hammingWeight(n) << endl;
    uint32_t n1 = 00000000000000000000000010000000;
    cout << sl.hammingWeight(n1) << endl;
    uint32_t n2 = 11111111111111111111111111111101;
    cout << sl.hammingWeight(n2) << endl;
    return 0;
}
