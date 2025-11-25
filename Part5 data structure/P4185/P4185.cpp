#include <bits/stdc++.h>
using namespace std;

int N, Q, pos = 1;
int f[100005], siz[100005], Ans[100005];

struct re{
    int p, q, r;
    bool operator < (const re &oth) const{
        return this->r > oth.r;
    }
}R[100005];

struct que{
    int k, v, id;
    bool operator < (const que &oth) const{
        return this->k > oth.k;
    }
}q[100005];

int Find(int x) {
    if (x == f[x]) return x;
    else return f[x] = Find(f[x]);
}

void Union(int x, int y) {
    int t1 = Find(x) ,t2 = Find(y);
    if (t1 != t2) f[t1] = t2, siz[t2] += siz[t1];
}

int main() {
    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N - 1; i++)
        scanf("%d%d%d", &R[i].p, &R[i].q, &R[i].r);
    for (int i = 1; i <= Q; i ++)
        scanf("%d%d", &q[i].k, &q[i].v), q[i].id = i;
    for (int i = 1; i <= N; i++)
        f[i] = i, siz[i] = 1;

    sort(R + 1, R + N);
    sort(q + 1, q + Q + 1);

    for (int i = 1; i <= Q; i++) {
        while (pos < N && R[pos].r >= q[i].k)
            Union(R[pos].p, R[pos].q), pos++;
        Ans[q[i].id] = siz[Find(q[i].v)] - 1;
    }

    for (int i = 1; i <= Q; i++)
        printf("%d\n", Ans[i]);
    return 0;
}