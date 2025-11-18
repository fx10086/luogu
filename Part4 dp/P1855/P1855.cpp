#include <bits/stdc++.h>
using namespace std;

int N, M, T, m[105], t[105], f[205][205];
int main() {
    scanf("%d%d%d", &N, &M, &T);
    for (int i = 1; i <= N; i++)
        scanf("%d%d", &m[i], &t[i]);
    
    for (int i = 1; i <= N; i++)
        for (int j = M; j >= m[i]; j--)
            for (int k = T; k >= t[i]; k--)
                f[j][k] = max(f[j][k], f[j - m[i]][k - t[i]] + 1);
    
    printf("%d\n", f[M][T]);
    return 0;
}