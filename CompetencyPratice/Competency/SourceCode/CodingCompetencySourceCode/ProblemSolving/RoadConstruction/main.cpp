#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int N;//Map Size
vector<vector<int>> arr;

struct Point
{
    int x;
    int y;
    int weight;
    Point(int x1, int y1, int weight1) {
        x = x1;
        y = y1;
        weight = weight1;
    }
};

struct CompareWeight
{
    bool operator()(const Point &a, const Point &b) {
        return a.weight > b.weight;
    }
};

void Input_Data(){
    cin >> N;
    arr = vector<vector<int>>(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < N; j++){
            arr[i][j] = input[j] - '0';
        }
    }
}

int main(){
    Input_Data();		//	Input function


    //	Write the code
    priority_queue<Point, vector<Point>, CompareWeight> pq;
    pq.push(Point(0, 0, 0));
    vector<int> r = {-1, 0, 1, 0};
    vector<int> c = {0, 1, 0, -1};
    vector<vector<int>> d(N, vector<int>(N, INT_MAX));
    d[0][0] = 0;
    while (!pq.empty()) {
        Point p = pq.top();
        pq.pop();
        for (int i = 0; i < 4; ++i) {
            int newX = p.x + r[i];
            int newY = p.y + c[i];
            if (newX < 0 || newX > N - 1) continue;
            if (newY < 0 || newY > N - 1) continue;
            if (d[newX][newY] > d[p.x][p.y] + arr[newX][newY]) {
                d[newX][newY] = d[p.x][p.y] + arr[newX][newY];
                pq.push(Point(newX, newY, d[newX][newY]));
            }
        }
    }
    cout << d[N - 1][N - 1] << endl;

    return 0;
}
