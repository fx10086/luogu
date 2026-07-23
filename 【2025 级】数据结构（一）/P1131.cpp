#include <bits/stdc++.h>
using namespace std;

const int N = 500010;
int head[N], cnt;
struct edge {
    int to, w, nxt;
} E[N << 1];
long long ans, dis[N];
int n, st;

void add(int x, int y, int z) {
    E[++cnt] = {y, z, head[x]};
    head[x] = cnt;
}

void dfs(int x, int fa) {
    for (int i = head[x]; i; i = E[i].nxt) {
        int y = E[i].to, z = E[i].w;
        if (y == fa) continue;
        dfs(y, x);
        dis[x] = max(dis[x], dis[y] + z);
    }
    for (int i = head[x]; i; i = E[i].nxt) {
        int y = E[i].to, z = E[i].w;
        if (y == fa) continue;
        ans += dis[x] - (dis[y] + z);
    }
}

int main() {
    cin >> n >> st;
    for (int i = 1; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    dfs(st, 0);
    cout << ans << '\n';
    return 0;
}