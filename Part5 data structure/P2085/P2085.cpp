#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N, M;
int A[MAXN], B[MAXN], C[MAXN], F[MAXN];
priority_queue < pair <int, int> > T;

int Cal(int i) {
    return A[i] * F[i] * F[i] + B[i] * F[i] + C[i];
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d%d", &A[i], &B[i], &C[i]);
        F[i] = 1;
        T.push(make_pair(-Cal(i), i));
    }

    for (int i = 1; i <= M; i++) {
        pair<int, int> x = T.top();
        T.pop();
        printf("%d ", -x.first);
        F[x.second]++;
        T.push(make_pair(-Cal(x.second), x.second));
    }
    return 0;
}