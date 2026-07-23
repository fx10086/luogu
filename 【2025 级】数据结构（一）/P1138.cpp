#include <bits/stdc++.h>
using namespace std;

int N, k;
int num[30005];

int main() {
    scanf("%d%d", &N, &k);
    for (int i = 1; i <= N; ++i) {
        int x; scanf("%d", &x);
        ++num[x];
    }

    for (int i = 1; i <= 30000; ++i) {
        if (num[i]) --k;
        if (!k) {
            printf("%d\n", i);
            break;
        }
    }
    if (k) printf("NO RESULT\n");
    return 0;
}