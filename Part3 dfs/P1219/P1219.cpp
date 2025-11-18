#include <bits/stdc++.h>
using namespace std;

int n, c[15], r[15], a[35], b[35], q[15], cnt;

void dfs(int i) {
    if (i > n) {
        if (cnt <= 2) { 
            for (int j = 1; j <= n; j++)
            printf("%d ", q[j]);
            puts("");
        }
        cnt++;
        return;
    }

    for (int j = 1; j <= n; j++) 
        if (!c[i] && !r[j] && !a[i + j] && !b[i - j + n]) {
            c[i] = r[j] = a[i + j] = b[i - j + n] = 1;
            q[i] = j;
            dfs(i + 1);
            c[i] = r[j] = a[i + j] = b[i - j + n] = q[i] = 0;
        }
}

int main() {
    scanf("%d", &n);
    dfs(1);
    printf("%d\n", cnt);
    return 0;
}