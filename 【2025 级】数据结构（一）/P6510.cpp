#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N, c[MAXN];
int st_Max[MAXN], stx;
int st_Min[MAXN], stn;

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &c[i]);
    
    int Ans = 0;
    for (int i = 1; i <= N; ++i) {
        while (stx && c[st_Max[stx]] <  c[i]) --stx;
        while (stn && c[st_Min[stn]] >= c[i]) --stn;
        int k = upper_bound(st_Min + 1, st_Min + stn + 1, st_Max[stx]) - st_Min;
        if (k != (stn + 1)) 
            Ans = max(Ans, i - st_Min[k] + 1);
        st_Max[++stx] = i;
        st_Min[++stn] = i;
    }
    
    printf("%d\n", Ans);
    return 0;
}