#include <bits/stdc++.h>
using namespace std;

int N, M, cnt, Ans, p[1005][1005], f[10000005];
struct edge{
    int u, v, w;
    friend bool operator < (const edge& a, const edge& b);
}E[10000005];

bool operator < (const edge& a, const edge& b) {
    return a.w < b.w;
}

int num(int i, int j) {
    return M * (i - 1) + j;
}

int Find(int x) {
    if (f[x] != x) return f[x] = Find(f[x]);
    return x;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) 
        for (int j = 1; j <= M; j++) {
            scanf("%d", &p[i][j]);
            f[num(i, j)] = num(i, j);
        }
    
    for (int i = 1; i <= N; i++) 
        for (int j = 1; j <= M; j++) {
            int a = num(i, j), b = num(i, j + 1), c = num(i + 1, j);
            if (j + 1 <= M) E[++cnt] = (edge){a, b, max(p[i][j], p[i][j + 1])};
            if (i + 1 <= N) E[++cnt] = (edge){a, c, max(p[i][j], p[i + 1][j])};
        }
    
    sort(E + 1, E + cnt + 1);

    int st = num(1, 1), ed = num(N, M);
    for (int i = 1; i <= cnt; i++) {
        int x = Find(E[i].u), y = Find(E[i].v);
        if (x != y) {
            Ans = max(Ans, E[i].w);
            f[x] = f[y];
            if (Find(st) == Find(ed)) break;
        }
    }

    printf("%d\n", Ans);
    return 0;
}