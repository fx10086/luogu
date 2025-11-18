#include <bits/stdc++.h>
using namespace std;

int N, rnk[500005], T[500005];
struct gt{
    int val, id;
}a[500005];

bool cmp (gt x, gt y) {
    if (x.val == y.val) return x.id < y.id;
    else return x.val < y.val;
}

int lowbit(int x) {
    return x & (-x);
}

void upd(int x) {
    for (; x <= N; x += lowbit(x))
        T[x]++;
}

int qry(int x) {
    int Ans = 0;
    for (; x; x -= lowbit(x))
        Ans += T[x];
    return Ans;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &a[i].val);
        a[i].id = i;
    }
    sort(a + 1, a + N + 1, cmp);
    for (int i = 1; i <= N; i++)
        rnk[a[i].id] = i;
    
    long long cnt = 0;
    for (int i = 1; i <= N; i++) {
        upd(rnk[i]);
        cnt += i - qry(rnk[i]);
    }
    printf("%lld\n", cnt);
    return 0;
}