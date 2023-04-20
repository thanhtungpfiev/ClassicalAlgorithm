#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;
const int dr[4] = {-1, 0, 0, 1}, dc[4] = { 0,-1, 1, 0};
const int MAX = 20, STATE = 1<<10;
int dist[STATE][MAX][MAX], H, W, total;
char A[MAX][MAX+5];
int bfs(int r, int c) {
    int ans = INT_MAX;
    queue< int > q;
    dist[0][r][c] = 0;
    q.push(r), q.push(c), q.push(0);
    while(!q.empty()) {
        r = q.front(); q.pop();
        c = q.front(); q.pop();
        int mask = q.front(); q.pop();
        for(int i=0; i<4; i++) {
            int vi = r + dr[i];
            int vj = c + dc[i];
            int vm = mask;
            if(vi>=0 && vi<H && vj>=0 && vj<W && A[vi][vj]!='x') {
                if(A[vi][vj] < total){
                    vm |= 1<<A[vi][vj];
                }
                if(dist[vm][vi][vj] > dist[mask][r][c]+1) {
                    dist[vm][vi][vj] = dist[mask][r][c] + 1;
                    if(vm==(1<<total)-1){
                        ans = min(ans, dist[vm][vi][vj]);
                    }
                    q.push(vi), q.push(vj), q.push(vm);
                }
            }
        }
    }
    return ((ans < INT_MAX) ? ans : -1);
}
int main() {
    int i, j, k, si, sj;
    while(scanf("%d%d", &W, &H)==2 &&(W+H)) {
        for(i=total=0; i<H; i++) {
            scanf("%s", A[i]);
            for(j=0; j<W; j++) {
                if(A[i][j]=='o') si = i, sj = j;
                else if(A[i][j]=='*') A[i][j] = total++;
            }
        }
        for(k=0; k<(1<<total); k++)
            for(i=0; i<H; i++)
                for(j=0; j<W; j++)
                    dist[k][i][j] = INT_MAX;
        printf("%d\n", bfs(si, sj));
    }
    return 0;
}
