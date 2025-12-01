#include <bits/stdc++.h>
using namespace std;

int cnt, head[200005];
struct edge{
    int to, nxt, w;
}E[200005];

void Add(int u, int v, int w) {
    E[++cnt] = (edge){v, head[u], w};
    head[u] = cnt;
}

priority_queue < pair<int, int> > q;
int dis[100005], N, M, s;
bool vis[100005];

void Dij() {
    for (int i = 1; i <= N; i++)
        dis[i] = INT_MAX;
    dis[s] = 0;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        else vis[u] = 1;
        for (int i = head[u]; i; i = E[i].nxt) {
            int v = E[i].to;
            if (dis[v] > dis[u] + E[i].w) {
                dis[v] = dis[u] + E[i].w;
                q.push(make_pair(-dis[v], v));
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
    Dij();
    return 0;
}