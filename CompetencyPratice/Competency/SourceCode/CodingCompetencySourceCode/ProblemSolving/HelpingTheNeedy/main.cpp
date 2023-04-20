/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 9/15/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int N;//The number of goods to send
const int num_of_kind  = 10;
vector<int> C(num_of_kind);//The number of BOXes(in order of 1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000)
vector<int> sol(num_of_kind);//The number of boxes to send
vector<int> Size = {1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000};

void InputData() {
    int i;
    cin >> N;
//    N = 267;
    for(i = 0; i < num_of_kind; i++) {
        cin >> C[i];
    }
//    C = {15, 6, 6, 3, 2, 2, 2, 2, 2, 1};
}
void OutputData(int ans) {
    int i;
    cout << ans << endl;
    for(i = 0; i < num_of_kind; i++) {
        cout << sol[i] << " ";
    }
    cout << endl;
}

bool pack(int &numberOfGoods, int &boxType) {
    if (numberOfGoods < Size[boxType] && sol[boxType] < C[boxType]) {
        return false;
    }
    if (sol[boxType] == C[boxType]) {
        ++boxType;
    } else {
        numberOfGoods -= Size[boxType];
        ++sol[boxType];
    }
    return true;
}

void adjustBox(int &numberOfGoods, int targetType, int sourceType) {
    while (sol[sourceType] > 0 && numberOfGoods + Size[sourceType] <= Size[targetType]) {
        --sol[sourceType];
        numberOfGoods += Size[sourceType];
    }
    if (numberOfGoods != Size[targetType]) {
        adjustBox(numberOfGoods, targetType, sourceType - 1);
    }
}

int main() {
    int ans = 0;

    InputData();//	Input function

    //	Create the code

    int boxType = 0;
    while (N > 0) {
        if (!pack(N, boxType)) {
            adjustBox(N, boxType, boxType - 1);
        }
    }

    for (int i = 0; i < num_of_kind; ++i) {
        ans += sol[i];
    }

    OutputData(ans);//	Output function

    return 0;
}
