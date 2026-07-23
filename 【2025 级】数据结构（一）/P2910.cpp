#include <bits/stdc++.h>
using namespace std;

int N, M, a[10005];
int dis[105][105];

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            scanf("%d", &dis[i][j]);
    
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    
    int res = 0;
    for (int i = 1; i < M; ++i)
        res += dis[a[i]][a[i + 1]];
    printf("%d\n", res);
    return 0;
}