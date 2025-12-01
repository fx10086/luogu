#include <bits/stdc++.h>
using namespace std;

int N;
string s;

char check(int l, int r) {
    int Sum = 0;
    for (int i = l; i <= r; i++)
        Sum += (s[i] - '0');
    if (!Sum) return 'B';
    else if (Sum == r - l + 1) return 'I';
    else return 'F';
}

void Tree(int l, int r) {
    if (l == r) {
        cout << check(l, r);
        return;
    }
    int Mid = (l + r) >> 1;
    Tree(l, Mid);
    Tree(Mid + 1, r);
    cout << check(l, r);
}

int main() {
    cin >> N >> s;
    s = ' ' + s;
    N = pow(2, N);
    Tree(1, N);
    return 0;
}