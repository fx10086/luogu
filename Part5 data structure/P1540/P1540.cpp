#include <bits/stdc++.h>
using namespace std;

int M, N, cnt[1005], Ans;
queue <int> q;

int main() {
    scanf("%d%d", &M, &N);
    for (int i = 1; i <= N; i++) {
        int a; scanf("%d", &a);
        if (!cnt[a]) {
            if (q.size() == M) 
                cnt[q.front()]--, q.pop();
            q.push(a), cnt[a]++, Ans++;
        }
    }
    printf("%d\n", Ans);
    return 0;
}