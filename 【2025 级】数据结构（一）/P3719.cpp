#include <bits/stdc++.h>
using namespace std;

int fun() {
    int Ans = 0;
    char c;
    while (cin >> c) {
        if (c == 'a') Ans++;
        else if (c == ')') return Ans;
        else if (c == '(') Ans = Ans + fun();
        else if (c == '|') return max(Ans, fun());
    }
    return Ans;
}

int main() {
    cout << fun() << '\n';
    return 0;
}