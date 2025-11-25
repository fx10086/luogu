#include <bits/stdc++.h>
using namespace std;

int N, M, T[500005], a[500005];

int lowbit(int x) {
    return x & (-x);
}

void Add(int x, int v) {
    for (int i = x; i <= N; i += lowbit(i))
        T[i] += v;
}

int Qry(int x) {
    int Ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        Ans += T[i];
    return Ans;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
        Add(i, a[i] - a[i - 1]);
    }
    for (int i = 1; i <= M; i++) {
        int op, x, y, k; 
        scanf("%d", &op);
        switch (op) {
            case 1:
                scanf("%d%d%d", &x, &y, &k);
                Add(x, k), Add(y + 1, -k);
                break;
            case 2:
                scanf("%d", &x);
                printf("%d\n", Qry(x));
        }
    }
    return 0;
}