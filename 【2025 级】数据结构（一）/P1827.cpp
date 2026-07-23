#include <bits/stdc++.h>
using namespace std;

string a, b;

void dfs(int la, int ra, int lb, int rb) {
    if (la > ra || lb > rb)
        return;
    for (int i = lb; i <= rb; ++i) 
        if (a[la] == b[i]) {
            dfs(la + 1, la + i - lb, lb, i - 1);
            dfs(la + i - lb + 1, ra, i + 1, rb);
            cout << b[i];
            break;
        }
}

int main() {
    cin >> b >> a;
    int l = a.size();
    dfs(0, l - 1, 0, l - 1);
    return 0;
}