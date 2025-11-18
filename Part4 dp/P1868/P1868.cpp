#include <bits/stdc++.h>
using namespace std;

int N, f[4000005], M;
vector<int>b[4000005];
int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        b[r].push_back(l - 1);
        M = max(M, r);
    }
    for (int i = 1; i <= M; i++) {
        f[i] = f[i - 1];
        for (int j = 0; j < b[i].size(); j++)
            f[i] = max(f[i], f[b[i][j]] + i - b[i][j]);
    }

    printf("%d\n", f[M]);
    return 0;
}