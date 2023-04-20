/**********************************************************************
 *
 * author tung.dao tung.dao@lge.com
 *
 * date 10/3/2021
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

struct Point {
    int x;
    int y;
    Point(int x1, int y1) {
        x = x1;
        y = y1;
    }
};

struct BFSPoint {
    int x;
    int y;
    int weight;
    BFSPoint(int x1, int y1, int weight1) {
        x = x1;
        y = y1;
        weight = weight1;
    }
};

struct CompareBFSPoint {
    bool operator()(const BFSPoint &a, const BFSPoint &b) {
        return a.weight > b.weight;
    }
};

bool myComp(const Point& a, const Point& b)
{
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

int bfs(Point& startPoint, Point& dirtyPoint, const vector<vector<char>>& map, int H, int W)
{
    vector<vector<int>> d(H, vector<int>(W, INT_MAX));
    priority_queue<BFSPoint, vector<BFSPoint>, CompareBFSPoint> pq;
    d[startPoint.x][startPoint.y] = 0;
    pq.push(BFSPoint(startPoint.x, startPoint.y,  d[startPoint.x][startPoint.y]));
    vector<int> r = {-1, 0, 1, 0};
    vector<int> c = {0, 1, 0, -1};
    while (!pq.empty()) {
        BFSPoint u = pq.top();
        pq.pop();
        if (u.weight == INT_MAX || (u.x == dirtyPoint.x && u.y == dirtyPoint.y)) {
            break;
        }
        for (int i = 0; i < 4; ++i) {
            int newX = u.x + r[i];
            int newY = u.y + c[i];
            if (newX < 0 || newX > H - 1) continue;
            if (newY < 0 || newY > W - 1) continue;
            if (map[newX][newY] == '.' || (newX == dirtyPoint.x && newY == dirtyPoint.y)) {
                if (d[newX][newY] > d[u.x][u.y] + 1) {
                    d[newX][newY] = d[u.x][u.y] + 1;
                    pq.push(BFSPoint(newX, newY, d[newX][newY]));
                }
            }
        }
    }
    return d[dirtyPoint.x][dirtyPoint.y];

}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int W, H;
    while(cin >> W >> H &&(W+H)) {
        vector<vector<char>> map(H, vector<char>(W));
        vector<Point> dirtyPoint;
        for (int i = 0; i < H; ++i) {
            string input;
            cin >> input;
            for (int j = 0; j < W; ++j) {
                map[i][j] = input[j];
            }
        }
        Point startPoint(0, 0);
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (map[i][j] == '*') {
                    dirtyPoint.push_back(Point(i, j));
                }
                if (map[i][j] == 'o') {
                    startPoint = Point(i, j);
                }
            }
        }
        int ans = INT_MAX;
        do {
            int result = 0;
            for (int i = 0; i < dirtyPoint.size(); ++i) {
                if (i == 0) {
                    int resultBFS = bfs(startPoint, dirtyPoint[i], map, H, W);
                    if (resultBFS == INT_MAX) {
                        result = resultBFS;
                        break;
                    }
                    result += resultBFS;
                } else {
                    int resultBFS = bfs(dirtyPoint[i - 1], dirtyPoint[i], map, H, W);
                    if (resultBFS == INT_MAX) {
                        result = resultBFS;
                        break;
                    }
                    result += resultBFS;
                }
            }
            ans = min(ans, result);
        } while (next_permutation(dirtyPoint.begin(), dirtyPoint.end(), myComp));
        if (ans == INT_MAX) {
            ans = -1;
        }
        cout << ans << endl;
    }

}
