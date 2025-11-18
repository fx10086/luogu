#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int inf = 1e13+7;
int N, f[1000005][3], x[1000005];
signed main() {
    scanf("%lld", &N);
    for (int i = 1; i <= N; i++)
        scanf("%lld", &x[i]);

    f[1][0] = f[1][1] = f[1][2] = inf;
    f[1][x[1] + 1] = 0;
    for (int i = 2; i <= N; i++) {
        if (x[i] == -1) {
            f[i][0] = f[i - 1][0];
            if (x[i - 1] == 1) {
                f[i][1] = min(f[i - 1][0], f[i - 1][1]) + 1;
                f[i][2] = min(f[i - 1][0], min(f[i - 1][1], f[i - 1][2])) + 2;
            } else {
                f[i][1] = inf;
                f[i][2] = f[i - 1][2] + 2;
            }
        }
        if (x[i] == 0) {
            f[i][0] = f[i - 1][0] + 1;
            f[i][1] = min(f[i - 1][0], f[i - 1][1]);
            if (x[i - 1] == 1) 
                f[i][2] = min(f[i - 1][0], min(f[i - 1][1], f[i - 1][2])) + 1;
            else 
                f[i][2] = f[i - 1][2] + 1;
        }
        if (x[i] == 1){
            f[i][0] = f[i - 1][0] + 2;
            if (x[i - 1] == -1)
                f[i][1] = min(f[i - 1][0], f[i - 1][1]) + 1;
            else
                f[i][1] = f[i - 1][0] + 1;
            f[i][2] = min(f[i - 1][0], min(f[i - 1][1], f[i - 1][2]));
        }
    }

    int Ans = min(f[N][0], min(f[N][1], f[N][2]));
    if (Ans >= inf) printf("BRAK\n");
    else printf("%lld\n", Ans);
    return 0;
}