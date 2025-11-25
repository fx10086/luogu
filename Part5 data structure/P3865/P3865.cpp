#include <bits/stdc++.h>
using namespace std;

int N, M, f[100005][20], Lg[100005];

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) 
        scanf("%d", &f[i][0]);
    
    Lg[1] = 0;
    for (int i = 2; i <= N; i++) 
        Lg[i] = Lg[i >> 1] + 1;
    
    for (int j = 1; j <= Lg[N]; j++) 
        for (int i = 1; i <= N - (1 << j) + 1; i++) 
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j -  1))][j - 1]);
    
    while (M--) {
        int l, r;
        scanf("%d%d", &l, &r);
        int k = Lg[r - l + 1];
        printf("%d\n", max(f[l][k], f[r - (1 << k) + 1][k]));
    }
    return 0;
}