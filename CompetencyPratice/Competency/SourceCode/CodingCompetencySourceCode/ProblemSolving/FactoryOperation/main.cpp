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
int bestChoice[50010];

void Input_Data(void){
    int i;
    cin >> N >> S;
    for (int i = 0; i < N; i++){
        cin >> C[i] >> Y[i];
    }
}

int main(){
    long long ans = 0;
    Input_Data();		//Input function

    // TODO : Write your codes.
    bestChoice[0] = C[0];
    for (int i = 1; i < N; ++i) {
        bestChoice[i] = min(C[i], bestChoice[i - 1] + S);
    }

    for (int i = 0; i < N; ++i) {
        ans += bestChoice[i] * Y[i];
    }

    cout << ans << endl;	//	Answer output
    return 0;
}
