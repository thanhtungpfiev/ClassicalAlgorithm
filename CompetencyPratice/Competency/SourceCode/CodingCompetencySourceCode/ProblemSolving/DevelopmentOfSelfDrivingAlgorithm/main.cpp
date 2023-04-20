/**********************************************************************
 *
 * author tung.dao tung.dao@lge.com
 *
 * date 9/19/2021
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;
int H;//Height
int W;//Width
char map[500][510];//map

struct Point {
    int x;
    int y;
    int weight;
    Point(int x1, int y1, int weight1) {
        x = x1;
        y = y1;
        weight = weight1;
    }
};

struct ComparePoint {
    bool operator()(const Point& a, const Point& b) {
        return a.weight > b.weight;
    }
};

void input_data(){
    int i;
    cin >> H >> W;
    for(i=0 ; i<H ; i++){
        cin >> map[i];
    }
}

int main(){
    int ans = 0;
    input_data();
    // Todo : write the code

    vector<vector<int>> d(H, vector<int>(W, INT_MAX));
    d[0][0] = 0;
    priority_queue<Point, vector<Point>, ComparePoint> pq;
    pq.push(Point(0, 0, d[0][0]));
    vector<int> r = {-1, 0, 1, 0};
    vector<int> c = {0, 1, 0, -1};
    while (!pq.empty()) {
        Point p = pq.top();
        pq.pop();

        // cout << p.x << " " << p.y << " " << p.weight << endl;
        if (d[p.x][p.y] == INT_MAX) {
            ans = -1;
            break;
        }
        for (int i = 0; i < 4; ++i) {
            int newX = p.x + r[i];
            int newY = p.y + c[i];
            if (newX < 0 || newX > H - 1) continue;
            if (newY < 0 || newY > W - 1) continue;
            if (map[newX][newY] == '.' && d[p.x][p.y] + 1 < d[newX][newY]) {
                d[newX][newY] = d[p.x][p.y] + 1;
                pq.push(Point(newX, newY, d[newX][newY]));
            }
        }
    }
    if (d[H - 1][W - 1] == INT_MAX) {
        ans = -1;
    } else {
        ans = d[H - 1][W - 1];
    }
    cout << ans << endl;
    return 0;
}
