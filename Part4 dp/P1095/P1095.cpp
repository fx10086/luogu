#include <bits/stdc++.h>
using namespace std;

int M, S, T, d1, d2;
int main() {
    scanf("%d%d%d", &M, &S, &T);
    for (int i = 1; i <= T; i++) {
        d1 += 17;
        d2 += (M >= 10) * 60;
        int m = M;
        M -= (m >= 10) * 10;
        M += (m < 10) * 4;
        if (d1 < d2) d1 = d2;
        if (d1 > S) {
            printf("Yes\n%d\n", i);
            return 0;
        }
    }
    printf("No\n%d\n", d1);
    return 0;
}