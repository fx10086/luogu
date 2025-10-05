#include <bits/stdc++.h>
using namespace std;

int Len, N, M, L, R, pos, cnt, a[50005], Mid, Ans;
int main() {
    scanf("%d%d%d", &Len, &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", &a[i]);
    
    a[N + 1] = Len;
    L = 1, R = Len;
    while (L <= R) {
        Mid = (L + R) >> 1, cnt = 0, pos = 0;
        for (int i = 1; i <= N + 1; i++) {
            if (a[i] - a[pos] < Mid) cnt++;
            else pos = i;
        }

        if (cnt > M) R = Mid - 1;
        else Ans = Mid, L = Mid + 1;
    }
    printf("%d\n", Ans);
    return 0;
}