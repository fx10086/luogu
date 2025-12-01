#include <bits/stdc++.h>
using namespace std;

int N, f[200005], cnt, Ans = 1e6 + 5;

int Find(int x) {
    cnt = 1;
    while (f[x] != x) 
        cnt++, x = f[x];
    return x;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        f[i] = i;
    for (int i = 1, t; i <= N; i++) {
        scanf("%d", &t);
        if (Find(t) == i) 
            Ans = min(Ans, cnt);
        else 
            f[i] = t;
    }
    printf("%d\n", Ans);
    return 0;
}