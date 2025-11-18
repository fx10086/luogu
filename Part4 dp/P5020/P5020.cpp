#include <bits/stdc++.h>
using namespace std;

int T, N, a[105], f[25005], Ans;
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N); Ans = N;
        for (int i = 1; i <= N; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + N + 1);

        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int i = 1; i <= N; i++) {
            if (f[a[i]]) 
                Ans--;
            else
                for (int j = a[i]; j <= a[N]; j++)
                    f[j] |= f[j - a[i]];
        }
        printf("%d\n", Ans);
    }
    return 0;
}