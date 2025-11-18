#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0,  0};
int dy[4] = {0,  0, 1, -1};

int N, M, Ans, p[1005][1005], vis[1005][1005], L, R;

bool bfs(int val) {
    queue< pair<int, int> > q;
    q.push(make_pair(1, 1));
    vis[1][1] = true;
    while (q.size()) {
        int xx = q.front().first, yy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i], ny = yy + dy[i];
            if (nx < 1 || nx > N || ny < 1 || ny > M || p[nx][ny] > val || vis[nx][ny])
                continue;
            vis[nx][ny] = true;
            q.push(make_pair(nx, ny));
            if (nx == N) return 1;
        }
    }
    return 0;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            scanf("%d", &p[i][j]);
            L = min(L, p[i][j]);
            R = max(R, p[i][j]);
        }
    
    while (L <= R) {
        int Mid = (L + R) >> 1;
        memset(vis, 0, sizeof(vis));
        if (bfs(Mid)) R = Mid - 1, Ans = Mid;
        else L = Mid + 1;
    }

    printf("%d\n", Ans);
    return 0;
}