#include <bits/stdc++.h>
using namespace std;

int N, M, f[100005][20];

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", &f[i][0]);
    for (int j = 1; j < 20; j++)
        for (int i = 1; i + (1 << (j - 1)) <= N; i++)
            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    
    N -= (M - 1);
    int m = log2(M);
    for (int i = 1, j = i + M - 1; i <= N; i++, j++)
        printf("%d\n", min(f[i][m], f[j - (1 << m) + 1][m]));
    return 0;
}