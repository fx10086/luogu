#include <bits/stdc++.h>
using namespace std;

int N, v[505][505], Ans;

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N - 1; i++) 
        for (int j = i + 1; j <= N; j++) {
            scanf("%d", &v[i][j]);
            v[j][i] = v[i][j];
        }

    for (int i = 1; i <= N; i++) {            
        sort(v[i] + 1, v[i] + N + 1);
        Ans = max(Ans, v[i][N - 1]);
    }

    printf("1\n%d\n", Ans);
    return 0;
}