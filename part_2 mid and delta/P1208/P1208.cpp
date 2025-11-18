#include <bits/stdc++.h>
using namespace std;

int N, M, cnt, Ans;
struct farmer{
    int p, a;
    friend bool operator < (const farmer& x, const farmer& y);
}f[5005];

bool operator < (const farmer& x, const farmer& y) {
    return x.p < y.p;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; i++) 
        scanf("%d%d", &f[i].p, &f[i].a);
    sort(f + 1, f + M + 1);

    while (f[++cnt].a <= N) 
        N -= f[cnt].a, Ans += f[cnt].p * f[cnt].a;
    Ans += N * f[cnt].p;

    printf("%d\n", Ans);
    return 0;
}