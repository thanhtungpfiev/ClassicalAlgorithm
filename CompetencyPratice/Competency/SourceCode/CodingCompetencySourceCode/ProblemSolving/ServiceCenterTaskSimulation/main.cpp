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
#include <climits>
using namespace std;

int N,Q;
int T[101];
int engineer[6];
int engineerTime[6];

void Input_Data(void){
    cin >> N >> Q;				// Number of engineers, number of customers
    for(int i=1;i<=Q;i++){
        cin >> T[i];				// Customer’s work processing time
    }
}

int main(void){
    int sol = INT_MIN;

    Input_Data();				// Input function

    // Write the code.
    int time = 0;
    int pos = 1;
    while (pos <=  Q) {
        for (int i = 1; i <= N; ++i) {
            if (engineerTime[i] == time && pos <= Q) {
                engineerTime[i] += T[pos];
                ++pos;
            }
        }
        ++time;
    }

    for (int i = 1; i <= N; ++i) {
        if (engineerTime[i] > sol) {
            sol = engineerTime[i];
        }
    }
    cout << sol << endl;	// Print answer
    return 0;
}
