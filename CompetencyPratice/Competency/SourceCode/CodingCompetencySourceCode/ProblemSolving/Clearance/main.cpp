/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 4/13/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int calculate(int M, vector<int>& order, vector<int>& count, vector<vector<int>>& numbers)
{
    int result = 0;
    int pos = 0;
    for (int i = 1; i <= M; ++i) {
        int num = order[i];
        pos += count[num];
        result += count[num] - (numbers[pos][num] - numbers[pos - count[num]][num]);
    }
    return result;
}

void generate(int i, int M, vector<int>& order, vector<bool>& mark, vector<int>& count, vector<vector<int>>& numbers, int& result)
{
    if (i > M) {
        int temp = calculate(M, order, count, numbers);
        if (temp < result) {
            result = temp;
        }
        return;
    }
    for (int v = 1; v <= M; ++v) {
        if (!mark[v]) {
            mark[v] = true;
            order[i] = v;
            generate(i + 1, M, order, mark, count, numbers, result);
            mark[v] = false;
        }
    }
}

int main()
{
    int N  = 0, M = 0;
    cin >> N >> M;
    vector<int> order(10);
    vector<bool> mark(10);
    vector<int> count(10);

    vector<vector<int>> numbers(N + 1, vector<int>(10));
    int temp = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> temp;
        for (int j = 1; j <= M; ++j) {
            numbers[i][j] = numbers[i - 1][j];
        }
        numbers[i][temp]++;
        count[temp]++;
    }
    int result = N + 1;
    generate(1, M, order, mark, count, numbers, result);
    cout << result << endl;

    return 0;
}
