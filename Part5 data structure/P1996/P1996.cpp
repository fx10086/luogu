#include <bits/stdc++.h>
using namespace std;

int N, M, t[1005], n, now = 1, P;

int lowbit (int x) {
    return x & (-x);
}

void Upd(int x, int v) {
    for (int i = x; i <= N; i += lowbit(i))
        t[i] += v;
}

int Find(int k) {
    int sum, pos; 
    sum = pos = 0;
    for (int i = 15; i >= 0; i--) {
        pos += (1 << i);
        if (pos > N || sum + t[pos] >= k)
            pos -= (1 << i);
        else 
            sum += t[pos]; 
    }
    return pos + 1;
}

int main() {
    scanf("%d%d", &N, &M); n = N;
    for (int i = 1; i <= N; i++)
        Upd(i, 1);
    while (n) {
        now = (now + M - 2) % n + 1;
        P = Find(now);
        Upd(P, -1);
        printf("%d ", P);
        n--;
    }
    return 0;
}