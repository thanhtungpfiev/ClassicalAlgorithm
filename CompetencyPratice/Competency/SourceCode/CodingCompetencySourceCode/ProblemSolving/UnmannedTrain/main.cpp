/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 9/4/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

struct Point
{
    int x;
    int y;
};

int dis(const Point& a, const Point& b)
{
    return abs(a.x  - b.x) + abs(a.y - b.y) - 1;
}

void BFS(vector<Point>& arr1, Point startPoint, const vector<int>& r, const vector<int> &c, vector<vector<int>>& arr, int N, int M)
{
    queue<Point> q;
    q.push(startPoint);
    while (!q.empty()) {
        Point p = q.front();
        q.pop();
        arr[p.x][p.y] = 0; // replacement color
        arr1.push_back(p);
        for (int i = 0; i < 4; ++i) {
            int newX = p.x + r[i];
            int newY = p.y + c[i];
            if (newX < 0 || newX >= N) continue;
            if (newY < 0 || newY >= M) continue;
            if (arr[newX][newY] == 1) { // target color
                Point newPoint;
                newPoint.x = newX;
                newPoint.y = newY;
                arr[newPoint.x][newPoint.y] = 0; // replacement color
                q.push(newPoint);
            }
        }
    }

}

int main()
{
    int N = 6, M = 16;
    cin >> N >> M;
    vector<vector<int>> arr(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
        }
    }

    vector<Point> A;
    vector<Point> B;
    vector<int> r = {-1, 0, 1, 0};
    vector<int> c = {0, 1, 0, -1};
    int countRegion = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (arr[i][j] == 1) {
                Point startPoint;
                startPoint.x = i;
                startPoint.y = j;
                if (countRegion == 0) {
                    BFS(A, startPoint, r, c, arr, N, M);
                    ++countRegion;
                } else {
                    BFS(B, startPoint, r, c, arr, N, M);
                }
            }
        }
    }
    int minDis = N * M;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < B.size(); ++j) {
            Point a = A[i];
            Point b = B[j];
            if (minDis > dis(a, b)) {
                minDis = dis(a, b);
            }
        }
    }

    cout << minDis << endl;

    return 0;
}
