/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 8/19/2021
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

int main()
{

    /* Kadane Algorithm
     */
    int n = 5;
    int arr[] = {1,2,3,-2,5};
    int max_so_far = INT8_MIN, max_ending_here = 0;
    for (int i = 0; i < n; ++i) {
        max_ending_here += arr[i];
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }
        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
    }
    cout << max_so_far << endl;

}
