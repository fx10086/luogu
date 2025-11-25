#include <bits/stdc++.h>
#define int long long 
using namespace std;

int T, N, h, r;
int f[1005], x[1005], y[1005], z[1005];

int Find(int x) {
    if (f[x] == x) return x;
    else return f[x] = Find(f[x]);
}

void Union(int x, int y) {
    int t1 = Find(x), t2 = Find(y);
    if (t1 != t2) f[t1] = f[t2];
}

int dist(int xx, int yy, int zz) {
    return xx * xx + yy * yy + zz * zz;
}

signed main() {
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld%lld%lld", &N, &h, &r);
        for (int i = 0; i <= N + 1; i++) 
            f[i] = i;
        for (int i = 1; i <= N; i++) {
            scanf("%lld%lld%lld", &x[i], &y[i], &z[i]);
            if (z[i] + r >= h) Union(i, N + 1);
            if (z[i] - r <= 0) Union(i, 0);
        }
        for (int i = 1; i < N; i++)
            for (int j = i + 1; j <= N; j++)
                if (dist(x[i] - x[j], y[i] - y[j], z[i] - z[j]) <= 4 * r * r)
                    Union(i, j);
        if (Find(0) == Find(N + 1)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}