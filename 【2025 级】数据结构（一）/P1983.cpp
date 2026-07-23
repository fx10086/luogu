#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int N, M, L, Ans;
int in[MAXN], s[MAXN];
bool vis[MAXN][MAXN], is[MAXN];
vector<int> E[MAXN];

int main() {
    scanf("%d%d", &N, &M);
    while (M--) {
        memset(is, 0, sizeof(is));
        scanf("%d", &L);
        for (int i = 1; i <= L; ++i) {
            scanf("%d", &s[i]);
            is[s[i]] = true;
        }
        for (int i = s[1]; i <= s[L]; ++i) {
            if (is[i]) continue;
            for (int j = 1; j <= L; ++j) {
                if (vis[i][s[j]]) continue;
                vis[i][s[j]] = 1;
                E[i].emplace_back(s[j]);
                ++in[s[j]];
            }
        }
    }

    queue < pair<int, int> > q;
    for (int i = 1; i <= N; ++i)
        if (!in[i]) q.push(make_pair(i, 1));
    
    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();
        for (auto &v :E[u.first]) {
            --in[v];
            if (!in[v]) {
                q.push(make_pair(v, u.second + 1));
                Ans = max(Ans, u.second + 1);
            }
        }
    }
    printf("%d\n", Ans);
    return 0;
}