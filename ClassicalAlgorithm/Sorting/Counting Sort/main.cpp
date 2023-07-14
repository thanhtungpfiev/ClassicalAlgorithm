/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 4/22/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> input  = {3, 4, 2, 1, 0, 0, 4, 3, 4, 2};
    vector<int> output(input.size());
    int min = input[0];
    int max = input[0];
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] < min) {
            min = input[i];
        } else if (input[i] > max) {
            max = input[i];
        }
    }
    vector<int> count(max - min + 1);
    for (int i = 0; i < input.size(); ++i) {
        count[input[i] - min]++;
    }
    for (int i = 1; i < count.size(); ++i) {
        count[i] += count[i - 1];
    }
    for (int i = 0; i < output.size(); ++i) {
        output[count[input[i] - min] - 1] = input[i];
        count[input[i] - min]--;
    }
    for (const auto e : output) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
