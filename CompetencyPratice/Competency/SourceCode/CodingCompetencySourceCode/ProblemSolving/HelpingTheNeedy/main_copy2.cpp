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
//    N = 7;
    for(i = 0; i < num_of_kind; i++) {
        cin >> C[i];
    }
//    C = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
}
void OutputData(int ans) {
    int i;
    cout << ans << endl;
    for(i = 0; i < num_of_kind; i++) {
        cout << sol[i] << " ";
    }
    cout << endl;
}

int calculate() {
    int result = 0;
    for (int i = 0; i < num_of_kind; ++i)
        result += sol[i] * Size[i];
    return result;
}

bool gen(int step) {
    int value = calculate();
    if (value == N) {
        return true;
    }
    if (value > N || step == num_of_kind) {
        return false;
    }
    for (int i = C[step]; i >= 0; --i) {
        sol[step] = i;
        if (gen(step + 1)) {
            return true;
        }
    }
}

int main(){
    int ans = 0;

    InputData();//	Input function

    //	Create the code

    gen(0);

    for (int i = 0; i < num_of_kind; ++i) {
        ans += sol[i];
    }

    OutputData(ans);//	Output function

    return 0;
}
