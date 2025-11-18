#include <bits/stdc++.h>
#define int long long
using namespace std;

int l, k, x[100005];
int L = 1, R, sum, Min = 1e14 + 7, Max = -1;

int check(int n) {
    int cnt = 0; sum = 0;
    for (int i = 1; i <= l; i++) {
        sum += x[i];
        if (sum < 0) sum = 0;
        if (sum >= n) sum = 0, cnt++;
    }
    return cnt;
}

signed main() {
    scanf("%lld%lld", &l, &k);
    for (int i = 1; i <= l; i++) {
        scanf("%lld", &x[i]);
        sum += x[i];
        if (sum < 0) sum = 0;
        R = max(R, sum);
    }

    int L1 = L, R1 = R;
    while (L <= R) {
        int Mid = (L + R) >> 1;
        if (check(Mid) <= k) {
            if (check(Mid) == k) Min = Mid;
            R = Mid - 1;
        }
        else L = Mid + 1;
    }
    while (L1 <= R1) {
        int Mid = (L1 + R1) >> 1;
        if (check(Mid) >= k) {
            if (check(Mid) == k) Max = Mid;
            L1 = Mid + 1;
        }
        else R1 = Mid - 1;
    }
    if (Min > Max) printf("-1\n");
    else printf("%lld %lld\n", Min, Max);
    return 0;
}