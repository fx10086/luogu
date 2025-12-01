#include <bits/stdc++.h>
using namespace std;

string Mid, Suc;

void Build(int l, int r, int L, int R) {
    if (l > r || L > R) return;
    int pos = Mid.find(Suc[R]);
    putchar(Suc[R]);
    if (pos > l) Build(l, pos - 1, L, R - r + pos - 1);
    if (pos < r) Build(pos + 1, r, L + pos - l,  R - 1);
}

int main() {
    cin >> Mid >> Suc;
    Mid = ' ' + Mid, Suc = ' ' + Suc;
    Build(1, Mid.size() - 1, 1, Suc.size() - 1);
    return 0;
}