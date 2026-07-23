#include <bits/stdc++.h>
using namespace std;

int N, st[3000005], top;
int x[3000005], f[3000005];

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &x[i]);
        while (top && x[st[top]] < x[i])
            f[st[top]] = i, --top;
        st[++top] = i;
    }

    for (int i = 1; i <= N; ++i)
        printf("%d ", f[i]);
    return 0;
}