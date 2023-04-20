/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 9/16/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
using namespace std;

int N;//Day
int S;//Storage cost
int C[50010];//Price
int Y[50010];//Capacity

void Input_Data(void){
    int i;
    cin >> N >> S;
    for (int i = 0; i < N; i++){
        cin >> C[i] >> Y[i];
    }
}

int main(){
    long long ans = -1;
    Input_Data();		//Input function

    // TODO : Write your codes.
    ans = C[0] * Y[0];
    for (int i = 1; i < N; ++i) {
        int minCost = C[i];
        for (int j = i -1; j >= 0; --j) {
            if (C[j] + (i - j) * S < minCost) {
                minCost = C[j] + (i - j) * S;
            }
        }
        ans += minCost * Y[i];
    }

    cout << ans << endl;	//	Answer output
    return 0;
}
