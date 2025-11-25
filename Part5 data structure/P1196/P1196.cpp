#include <bits/stdc++.h>
using namespace std;

int T;
int f[30005], num[30005], dis[30005];

int Find(int x) {
    if (f[x] == x) return x;
    int F = Find(f[x]);
    dis[x] += dis[f[x]];
    return f[x] = F;
}

void Union(int x, int y) {
    int t1 = Find(x), t2 = Find(y);
    if (t1 != t2) {
        f[t1] = t2;
        dis[t1] = num[t2];
        num[t2] += num[t1];
        num[t1] = num[t2];
    }
}

int Qry(int x, int y) {
    int t1 = Find(x), t2 = Find(y);
    if (t1 != t2) return -1;
    else return abs(dis[x] - dis[y]) - 1;
}

int main() {
    scanf("%d", &T);
    for (int i = 1; i <= 30000; i++)
        f[i] = i, num[i] = 1;
    while (T--) {
        char C; int i, j;
        cin >> C;
        scanf("%d%d", &i, &j);
        if (C == 'M') Union(i , j);
        if (C == 'C') printf("%d\n", Qry(i, j));
    }
    return 0;
}