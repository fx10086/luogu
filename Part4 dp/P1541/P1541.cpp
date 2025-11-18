#include <bits/stdc++.h>
using namespace std;

int N, M, f[150][150][150][150], x[400], p[5];
int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", &x[i]);
    for (int i = 1;i <= M; i++) {
        int b; scanf("%d", &b);
        p[b]++;
    } 
    f[0][0][0][0] = x[1];
    for (int a = 0; a <= p[1]; a++)
        for (int b = 0; b <= p[2]; b++)
            for (int c = 0; c <= p[3]; c++)
                for (int d = 0; d <= p[4]; d++) {
                    int r = 1 + a + 2 * b + 3 * c + 4 * d;
                    if (a > 0) f[a][b][c][d] = max(f[a][b][c][d], f[a - 1][b][c][d] + x[r]);
                    if (b > 0) f[a][b][c][d] = max(f[a][b][c][d], f[a][b - 1][c][d] + x[r]);
                    if (c > 0) f[a][b][c][d] = max(f[a][b][c][d], f[a][b][c - 1][d] + x[r]);
                    if (d > 0) f[a][b][c][d] = max(f[a][b][c][d], f[a][b][c][d - 1] + x[r]);
                }
    
    printf("%d\n", f[p[1]][p[2]][p[3]][p[4]]);
    return 0;
}