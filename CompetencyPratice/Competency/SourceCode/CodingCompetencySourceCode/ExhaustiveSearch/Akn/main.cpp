/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 8/15/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <algorithm>
#include "TryConfig.h"

using namespace std;

template  <class  BidirectionalIterator >
bool next_partial_permutation(
  BidirectionalIterator  first ,
  BidirectionalIterator  middle ,
  BidirectionalIterator  last)
{
  std::reverse(middle , last);
  return std::next_permutation(first , last);
}

int main()
{
    int n = 5;
    int k = 3;
    // Thuat toan quay lui
    cout << "Thuat toan quay lui: " << endl;
    if (n > 0) {
        TryConfig t(n, k);
        t.tryConfig(1);
    }

    vector<int> v = {1, 2, 3, 4, 5};
    int count = 1;
    do {
        cout << count << ": ";
        for (int i = 0; i < 3; ++i) {
            cout << v[i] << " ";
        }
        ++count;
        cout << endl;
    } while (next_partial_permutation(v.begin(), v.begin() + k, v.end()));
    return 0;
}
