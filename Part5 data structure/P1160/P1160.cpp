#include <bits/stdc++.h>
using namespace std;

int N, M, pos;
int l[100005], r[100005];
bool flag[100005];
int main() {
    scanf("%d", &N);
    for (int i = 2; i <= N; i++) {
        int k, p;
        scanf("%d%d", &k, &p);
        if (!p) 
            l[i] = l[k], r[i] = k, l[k] = i, r[l[i]] = i;
        else 
            r[i] = r[k], l[i] = k, r[k] = i, l[r[i]] = i;
    }
    
    scanf("%d", &M);
    for (int i = 1; i <= M; i++) {
        int x;
        scanf("%d", &x);
        flag[x] = true;
    }

    for (int i = 1; i <= N; i++) 
        if (!l[i]) {
            pos = i;
            break;
        }

    for (int i = 1; i <= N; i++) {
        if (!flag[pos])
            printf("%d ", pos);
        pos = r[pos];
    }
    return 0;
}