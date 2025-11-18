#include <bits/stdc++.h>
using namespace std;

int M, N;
int cnt[105], w[105][1005], v[105][1005];
int f[1005];

int main() {
    scanf("%d%d", &M, &N);
    for (int i = 1; i <= N; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        cnt[c]++;
        w[c][cnt[c]] = a, v[c][cnt[c]] = b;
    }

    for (int k = 1; k <= 100; k++) 
        for (int j = M; j >= 0; j--)
            for (int i = 1; i <= cnt[k]; i++)
                if (j >= w[k][i])
                    f[j] = max(f[j], f[j - w[k][i]] + v[k][i]);
    
    printf("%d\n", f[M]);
    return 0;
}