/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 9/8/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
using namespace std;

long long N;//Number of employees
long long T;//Walking Time (in minutes)
long long P[100000 + 10];//Starting location of emplyees
long long S[100000 + 10];//Walking speed of emplyees (per minute)

void InputData(){
    cin >> N >> T;
    for (int i = 0; i < N; i++){
        cin >> P[i] >> S[i];
    }
}

int main(){
    long long ans = -1;

    InputData();			//	Input function

    //	Write the code
    vector<long long> ActualLocation(N);
    ActualLocation[N - 1] = P[N - 1] + T * S[N - 1];
    for (int i = N - 2; i >= 0; --i) {
        ActualLocation[i] = P[i] + T * S[i];
        if (ActualLocation[i] > ActualLocation[i + 1]) {
            ActualLocation[i] = ActualLocation[i + 1];
        }
    }

    ans = 1;
    for (int i = 0; i < N - 1; ++i) {
        if (ActualLocation[i] != ActualLocation[i + 1]) {
            ans++;
        }
    }
    cout << ans << endl;	//	Output right answer
    return 0;
}
