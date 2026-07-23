#include <bits/stdc++.h>
using namespace std;

int N, f[200005], cnt;

int main() {
    scanf("%d", &N);
    while (N--) {
        int op, x;
        scanf("%d", &op);
        if (op == 0) {
            scanf("%d", &x);
            ++cnt;
            f[cnt] = max(f[cnt - 1], x);
        } else if (op == 1) 
            --cnt;
        else printf("%d\n", f[cnt]);
    }
    return 0;
}