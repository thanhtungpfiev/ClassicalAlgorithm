/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 9/3/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
using namespace std;

int N;
int A[30 + 10];
int sol[30 + 10];
int from[30 + 10];

void InputData(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
}

void OutputData(){
    cout << N << endl;
    for(int i=0;i<N;i++){
        cout << sol[i] << " ";
    }
    cout << endl;
}

bool isValidIndex(int index, int step){
    for (int i = 0; i < step; ++i) {
        if (index == from[i]) {
            return false;
        }
    }
    return true;
}

void BuildFromArray(){
    from[0] = 0;
    for (int i = 1; i < N; ++i) {
        int index = (from[i - 1] + A[i - 1]) % N;
        while (!isValidIndex(index, i)) {
            index = (index + 1) % N;
        }
        from[i] = index;
    }
}

void BuildSolArray(){
    for (int i = 0; i < N; ++i) {
        sol[from[i]] = A[i];
    }
}

int main(){
    InputData();//	입력 함수
    BuildFromArray();
    BuildSolArray();
    //	코드를 작성하세요

    OutputData();//출력
    return 0;
}

