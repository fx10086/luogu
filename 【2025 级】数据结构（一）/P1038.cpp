#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int N, M;

bool vis[MAXN];
queue<int> q;

int head[MAXN], cnt;
struct edge {
    int to, w, nxt;
}E[MAXN * MAXN];

bool out[MAXN];
struct {
    int c, u;
}x[MAXN];

void Add_Edge() {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    ++cnt;
    E[cnt] = (edge){v, w, head[u]};
    head[u] = cnt;
    out[u] = 1;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        scanf("%d%d", &x[i].c, &x[i].u);
        if (x[i].c) {
            vis[i] = 1;
            q.push(i);
        } else 
            x[i].c -= x[i].u;
    }

    while (M--) Add_Edge();

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (x[u].c <= 0) continue;
        for (int i = head[u]; i; i = E[i].nxt) {
            int v = E[i].to;
            x[v].c += x[u].c * E[i].w;
            if (!vis[v]) {
                q.push(v);
                vis[v] = 1;
            }
        }
    }

    bool flag = 0;
    for (int i = 1; i <= N; ++i)
        if (!out[i] && x[i].c > 0) {
            printf("%d %d\n", i, x[i].c);
            flag = 1;
        }
    if (!flag) puts("NULL");
    return 0;
}