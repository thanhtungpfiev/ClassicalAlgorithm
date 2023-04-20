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

const int GOOD_0 = 1;
const int GOOD_1 = 5;
const int GOOD_2 = 10;
const int GOOD_3 = 50;
const int GOOD_4 = 100;
const int GOOD_5 = 500;
const int GOOD_6 = 1000;
const int GOOD_7 = 3000;
const int GOOD_8 = 6000;
const int GOOD_9 = 12000;

int main()
{
    int N = 267;
    cin >> N;
//    vector<int> C = {15, 6, 6, 3, 2, 2, 2 ,2, 2, 1};
    vector<int> C(N);
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }
    int i0max = 0;
    int i1max = 0;
    int i2max = 0;
    int i3max = 0;
    int i4max = 0;
    int i5max = 0;
    int i6max = 0;
    int i7max = 0;
    int i8max = 0;
    int i9max = 0;
    int num = i0max + i1max + i2max + i3max + i4max + i5max + i6max + i7max + i8max + i9max;
    for (int i0 = 0; i0 <= C[0]; ++i0) {
        for (int i1 = 0; i1 <= C[1]; ++i1) {
            for (int i2 = 0; i2 <= C[2]; ++i2) {
                for (int i3 = 0; i3 <= C[3]; ++i3) {
                    for (int i4 = 0; i4 <= C[4]; ++i4) {
                        for (int i5 = 0; i5 <= C[5]; ++i5) {
                            for (int i6 = 0; i6 <= C[6]; ++i6) {
                                for (int i7 = 0; i7 <= C[7]; ++i7) {
                                    for (int i8 = 0; i8 <= C[8]; ++i8) {
                                        for (int i9 = 0; i9 <= C[9]; ++i9) {
                                            int temp = i0 * GOOD_0 + i1 * GOOD_1 + i2 * GOOD_2 + i3 * GOOD_3 + i4 * GOOD_4
                                                        + i5 * GOOD_5 + i6 * GOOD_6 + i7 * GOOD_7 + i8 * GOOD_8 + i9 * GOOD_9;
                                            if (temp == N) {
                                                if ( i0 + i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9 > num) {
                                                    num = i0 + i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9;
                                                    i0max = i0;
                                                    i1max = i1;
                                                    i2max = i2;
                                                    i3max = i3;
                                                    i4max = i4;
                                                    i5max = i5;
                                                    i6max = i6;
                                                    i7max = i7;
                                                    i8max = i8;
                                                    i9max = i9;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << num << endl;
    cout << i0max << " " << i1max << " " << i2max << " " << i3max << " " << i4max
         << " " << i5max << " " << i6max << " " << i7max << " " << i8max << " " << i9max << endl;
    return 0;
}
