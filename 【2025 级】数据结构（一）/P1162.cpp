#include <bits/stdc++.h>
using namespace std;

int N, a[35][35];

int dx[4] = {  0,  0,  1, -1};
int dy[4] = {  1, -1,  0,  0};

void dfs(int x, int y) {
    if (x < 0 || y < 0 || x > N + 1 || y > N + 1 || a[x][y] != 0) 
        return;
    a[x][y] = -1;
    for (int i = 0; i < 4; ++i)
        dfs(x + dx[i], y + dy[i]);
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            scanf("%d", &a[i][j]);
    
    dfs(0, 0);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j)
            if (a[i][j] == -1) printf("0 ");
            else if (a[i][j] == 1) printf("1 ");
            else printf("2 ");
        puts("");
    }
    return 0;
}