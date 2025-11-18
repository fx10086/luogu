#include <bits/stdc++.h>
using namespace std;

int N, M;
int Left = 1e6+5, Right, Mid;
long long S, num[200005], sum[200005], Ans = 1e12+6, Y;
int l[200005], r[200005];
struct rock{
    int w, v;
}R[200005];

bool check(int W) {
    Y = 0;
    memset(num, 0, sizeof(num));
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= N; i++) 
        if (R[i].w >= W) 
            sum[i] = sum[i - 1] + R[i].v, num[i] = num[i - 1] + 1;
        else
            sum[i] = sum[i - 1], num[i] = num[i - 1];

    for (int i = 1; i <= M; i++) 
        Y += (num[r[i]] - num[l[i] - 1]) * (sum[r[i]] - sum[l[i] - 1]);
    
    if (Y >= S) return 0;
    else return 1;
}

int main() {
    scanf("%d%d%lld", &N, &M, &S);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &R[i].w, &R[i].v);
        Left = min(Left, R[i].w), Right = max(Right, R[i].w);
    }
    for (int i = 1; i <= M; i++)
        scanf("%d%d", &l[i], &r[i]);

    while (Left <= Right) {
        Mid = (Left + Right) >> 1;
        if (check(Mid)) Right = Mid - 1;
        else Left = Mid + 1;
        Ans = min(Ans, llabs(Y - S));
    }

    printf("%lld\n", Ans);
    return 0;
}