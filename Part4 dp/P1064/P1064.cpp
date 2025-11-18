#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e8;
int N, F, r[2005], f[2005][1005];
int main() {
    scanf("%d%d", &N, &F);
    for (int i = 1; i <= N; i++) 
        scanf("%d", &r[i]), r[i] %= F, f[i][r[i]] = 1;
    
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < F; j++)
            f[i][j] = (f[i][j] + f[i - 1][j] % MOD + f[i - 1][(j - r[i] + F) % F] % MOD) % MOD;
    
    printf("%d\n", f[N][0]);
    return 0;
}