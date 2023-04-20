/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 8/19/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cfloat>

using namespace std;

struct Point
{
    long int x = 0;
    long int y = 0;
};

int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}

double distance(const Point& p1, const Point& p2) {
    double result = 0;
    result = sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
    return result;
}

int X, Y, X1, Y1, minI, minJ;

double bruteForce(Point P[], int n)
{
    double min = DBL_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (distance(P[i], P[j]) < min) {
                min = distance(P[i], P[j]);
            }
    return min;
}

double stripClosest(Point strip[], int size, double d)
{
    double min = d; // Initialize the minimum distance as d

    qsort(strip, size, sizeof(Point), compareY);

    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (distance(strip[i],strip[j]) < min) {
                min = distance(strip[i], strip[j]);
            }

    return min;
}

double closestUtil(Point P[], int n)
{
    if (n <= 3)
        return bruteForce(P, n);

    int mid = n/2;
    Point midPoint = P[mid];

    double dl = closestUtil(P, mid);
    double dr = closestUtil(P + mid, n - mid);

    double d = min(dl, dr);

    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;
    double d1 = stripClosest(strip, j, d);
    if (d > d1) {
        minI = X1;
        minJ = Y1;
    } else {
        minI = X;
        minJ = Y;
    }

    return min(d, stripClosest(strip, j, d));
}

int main()
{
    int N;
    cin >> N;
    int temp_x = 0, temp_y = 0;
    Point P[N];
    for (int i = 0; i < N; ++i) {
        cin >> temp_x >> temp_y;
        Point temp_p;
        temp_p.x = temp_x;
        temp_p.y = temp_y;
        P[i] = temp_p;
    }
    /* brute force
    double minDis = distance(arr[0], arr[1]);
    int minI = 0, minJ = 1;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            double dis = distance(arr[i], arr[j]);
            if (minDis > dis) {
                minDis = dis;
                minI = i;
                minJ = j;
            }
        }
    }
    cout << minI << " " << minJ << " " << setprecision(6) << fixed << minDis << endl;
    */
    /* divine and conquer
     */
    qsort(P, N, sizeof(Point), compareX);
    double minDis = closestUtil(P, N);
    cout << minI << " " << minJ << " " << setprecision(6) << fixed << minDis << endl;
    return 0;
}
