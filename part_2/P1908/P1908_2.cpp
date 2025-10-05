#include <bits/stdc++.h>
using namespace std;

int N, a[500005], c[500005];
long long cnt;

void Mge(int l, int r) {
    if (l >= r) return;
    int mid = (l + r) >> 1, i = l, j = mid + 1, pos = l;
    Mge(l, mid), Mge(mid + 1, r);
    while (i <= mid && j <= r) {
        if (a[i] <= a[j])
            c[pos++] = a[i++];
        else 
            c[pos++] = a[j++], cnt += mid - i + 1;
    }
    while (i <= mid) c[pos++] = a[i++];
    while (j <= r) c[pos++] = a[j++];
    for (int k = l; k <= r; k++) a[k] = c[k];
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &a[i]);
    Mge(1, N);
    printf("%lld\n", cnt);
    return 0;
}