#include <bits/stdc++.h>
#define int long long
#define ls rt << 1
#define rs rt << 1 | 1
#define MAXN 100005

using namespace std;

struct tree {
    int l, r;
    int val, laz;
}T[MAXN << 2];

int N, M, a[MAXN];

void Up(int rt) {
    T[rt].val = T[ls].val + T[rs].val;
}

void Spread(int rt) {
    if (!T[rt].laz) return;
    T[ls].val += T[rt].laz * (T[ls].r - T[ls].l + 1);
    T[rs].val += T[rt].laz * (T[rs].r - T[rs].l + 1);
    T[ls].laz += T[rt].laz, T[rs].laz += T[rt].laz;
    T[rt].laz = 0;
}

void Build(int rt, int L, int R) {
    T[rt].l = L, T[rt].r = R;
    if (L == R) {
        T[rt].val = a[L];
        return;
    }
    int Mid = (L + R) >> 1;
    Build(ls, L, Mid);
    Build(rs, Mid + 1, R);
    Up(rt);
}

void Upd(int rt, int x, int y, int k) {
    if (x <= T[rt].l && y >= T[rt].r) {
        T[rt].val += (T[rt].r - T[rt].l + 1) * k;
        T[rt].laz += k;
        return;
    }
    Spread(rt);
    int Mid = (T[rt].l + T[rt].r) >> 1;
    if (x <= Mid) Upd(ls, x, y, k);
    if (y >  Mid) Upd(rs, x, y, k);
    Up(rt);
}

int Qry(int rt, int x, int y) {
    if (x <= T[rt].l && y >= T[rt].r)
        return T[rt].val;
    Spread(rt);
    int Mid = (T[rt].l + T[rt].r) >> 1, Ans = 0;
    if (x <= Mid) Ans += Qry(ls, x, y);
    if (y >  Mid) Ans += Qry(rs, x, y);
    return Ans;
}

signed main() {
    scanf("%lld%lld", &N ,&M);
    for (int i = 1; i <= N; i++)
        scanf("%lld", &a[i]);
    Build(1, 1, N); 
    while (M--) {
        int op, x, y, k;
        scanf("%lld", &op);
        switch(op) {
            case 1:
                scanf("%lld%lld%lld", &x, &y, &k);
                Upd(1, x, y, k);
                break;
            case 2:
                scanf("%lld%lld", &x, &y);
                printf("%lld\n", Qry(1, x, y));
                break;
        }
    }
    return 0;
}