/*
 * File: main.cpp
 * Project: 66thProblem
 * File Created: Wednesday, 2nd March 2022 5:30:01 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <algorithm>
using namespace std;

int N;             // Number of executable code data
int M;             // Number of virus data
int A[20000 + 10]; // Executable code data
int B[10 + 10];    // Virus data
int tmp[10 + 10];

int sol; // Correct answer

void InputData(void)
{
    int i;

    cin >> N >> M;

    for (i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (i = 0; i < M; i++)
    {
        cin >> B[i];
    }
}

void OutputData(void)
{
    cout << sol;
}

int Find(int start)
{
    int i;

    for (int i = 0; i < M; ++i)
    {
        tmp[i] = A[start + i];
    }
    sort(tmp, tmp + M);
    int diff = B[0] - tmp[0];
    for (i = 1; i < M; i++)
    {
        if (B[i] != tmp[i] + diff)
            return 0;
    }
    return 1;
}

void Solve(void)
{
    int i;
    sort(B, B + M);
    for (i = 0; i <= N - M; i++)
    {
        sol += Find(i);
    }
}

int main(void)
{
    InputData(); // Input

    Solve(); // Problem solving

    OutputData(); // Output

    return 0;
}
