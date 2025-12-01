#include <bits/stdc++.h>
using namespace std;

int cnt, head[500005];
struct edge{
    int to, nxt, w;
}E[500005];

void Add(int u, int v, int w) {
    E[++cnt] = (edge){v, head[u], w};
    head[u] = cnt;
}

queue<int> q;
bool vis[10005];
int dis[10005], N, M, s;

void Spfa() {
    for (int i = 1; i <= N; i++)
        dis[i] = INT_MAX;
    q.push(s), vis[s] = 1, dis[s] = 0;;
    while (!q.empty()) {
        int u = q.front();
        q.pop(), vis[u] = 0;
        for (int i = head[u]; i; i = E[i].nxt) {
            int v = E[i].to;
            if (dis[v] > dis[u] + E[i].w) {
                dis[v] = dis[u] + E[i].w;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= N; i++)
        printf("%d ", dis[i]);
}

int main() {
    scanf("%d%d%d", &N, &M, &s);
    for (int i = 1, u, v, w; i <= M; i++) {
        scanf("%d%d%d", &u, &v, &w);
        Add(u, v, w);
    }
    Spfa();
    return 0;
}