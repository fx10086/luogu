#include <bits/stdc++.h>
using namespace std;

int N, l[1000005], r[1000005];

int dfs(int rt) {
    int Ans = 0;
    if (l[rt]) Ans = dfs(l[rt]) + 1;
    if (r[rt]) Ans = max(Ans, dfs(r[rt]) + 1);
    return Ans;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        scanf("%d%d", &l[i], &r[i]);
    printf("%d\n", dfs(1) + 1);
    return 0;
}