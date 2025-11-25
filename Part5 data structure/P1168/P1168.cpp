#include <bits/stdc++.h>
using namespace std;

int T[100005], N, cnt;
int a[100005], b[100005];

int lowbit(int x) {
    return x & (-x);
}

void Upd(int x) {
    for (int i = x; i <= cnt; i += lowbit(i))
        T[i]++;
}

int Qry(int k) {
    int now = 0, sum = 0;
    for (int i = 20; i >= 0; i--) {
        now += (1 << i);
        if (now > cnt || sum + T[now] >= k) 
            now -= (1 << i);
        else 
            sum += T[now];
    }
    return now + 1;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &a[i]), b[i] = a[i];
    sort(a + 1, a + N + 1);
    cnt = unique(a + 1, a + N + 1) - a - 1;
    for (int i = 1; i <= N; i++)
        b[i] = lower_bound(a + 1, a + N + 1, b[i]) - a;
    for (int i = 1; i <= N; i++) { 
        Upd(b[i]);
        if (i & 1) 
            printf("%d\n", a[Qry((i + 1) >> 1)]);
    }
    return 0;
}