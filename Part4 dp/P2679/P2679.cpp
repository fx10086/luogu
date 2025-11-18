#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
int n, m, k;
string a, b;
int f[1005][205], g[1005][205], s[1005][205];

int main() {
    scanf("%d%d%d", &n, &m, &k); 
    cin >> a >> b;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++) 
            for (int t = 1; i + t <= n && j + t <=m; t++)
                if (a[i + t - 1] == b[j + t - 1])
                    s[i][j]++;
                else 
                    break;
    
    f[0][0] = 1, f[1][1] = -1;
    for (int t = 0; t <= k; t++) {
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++) {
                if (i > 0 && j > 0) 
                    f[i][j] = (f[i - 1][j - 1] % MOD + f[i][j]) % MOD;

                f[i + 1][j] = (f[i][j] % MOD + f[i + 1][j]) % MOD;
                f[i + 2][j + 1] = (f[i + 2][j + 1] + MOD - f[i][j] % MOD) % MOD;

                g[i + 1][j + 1] = (g[i + 1][j + 1] + f[i][j] % MOD) % MOD;
                g[i + s[i][j] + 1][j + s[i][j] + 1] = (g[i + s[i][j] + 1][j + s[i][j] + 1] + MOD - f[i][j] % MOD) % MOD;
            }
        if (t == k) {
            printf("%d\n", f[n][m] % MOD);
            return 0;
        }    
        swap(f, g);
        memset(g, 0, sizeof(g));
    }
    return 0;
}