#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int N;
int nxt[MAXN], dfn[MAXN], col[MAXN], cir[MAXN], fir[MAXN];

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) 
        scanf("%d", &nxt[i]);
    
    for (int cow = 1; cow <= N; cow++) 
        for (int i = cow, cnt = 0; ; i = nxt[i], cnt++) 
            if (!col[i]) 
                col[i] = cow, dfn[i] = cnt;
            else if (col[i] == cow) {
                cir[cow] = cnt - dfn[i];
                fir[cow] = dfn[i];
                printf("%d\n", cnt);
                break;
            } else {
                cir[cow] = cir[col[i]];
                fir[cow] = cnt + max(0, fir[col[i]] - dfn[i]); 
                printf("%d\n", cir[cow] + fir[cow]);
                break;
            }
    return 0;
}