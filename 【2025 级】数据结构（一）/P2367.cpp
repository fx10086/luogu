#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e6 + 5;
int n, p;
int a[MAXN], T[MAXN];

int main() {
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        T[i] = a[i] - a[i - 1];
    }

    while (p--) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        T[l] += x, T[r + 1] -= x;
    }

    int sum = 0, Min = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        sum += T[i];
        Min = min(Min, sum);
    }

    printf("%d\n", Min);
    return 0;
}