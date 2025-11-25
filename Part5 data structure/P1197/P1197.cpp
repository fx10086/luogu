#include <bits/stdc++.h>
using namespace std;

int N, M, K, k[200005];
int x[200005], y[200005];
int f[400005], Ans[400005];
int sum, head[400005], cnt;
bool flag[400005];

struct edge{
    int nxt, to;
}E[400005];

void Add(int u, int v) {
    E[++cnt] = (edge){head[u], v};
    head[u] = cnt;
    E[++cnt] = (edge){head[v], u};
    head[v] = cnt;
}

int Find(int x) {
    if (f[x] == x) return x;
    else return f[x] = Find(f[x]);
}

void Union(int x, int y) {
    int t1 = Find(x), t2 = Find(y);
    if (t1 != t2) sum--, f[t1] = t2;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) 
        f[i] = i;
    for (int i = 1; i <= M; i++)
        scanf("%d%d", &x[i], &y[i]), Add(x[i], y[i]);
    scanf("%d", &K);
    sum = N - K;
    for (int i = 1; i <= K; i++)
        scanf("%d", &k[i]), flag[k[i]] = true;
    
    for (int i = 1; i <= M; i++)
        if (!(flag[x[i]] | flag[y[i]]))
            Union(x[i], y[i]);
    
    Ans[K + 1] = sum;
    for (int i = K; i >= 1; i--) {
        flag[k[i]] = false, sum++;
        for (int j = head[k[i]]; j != 0; j = E[j].nxt)
            if (!flag[E[j].to]) Union(k[i], E[j].to);
        Ans[i] = sum;
    }

    for (int i = 1; i <= K + 1; i++)
        printf("%d\n", Ans[i]);
    return 0;
}