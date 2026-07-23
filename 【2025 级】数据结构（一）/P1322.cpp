#include <bits/stdc++.h>
using namespace std;

int fun() {
    string s;
    int num, Ans = 0;
    while (cin >> s) {
        if (s[0] == ']') break;
        cin >> num;
        if (s[0] == 'F') Ans += num;
        else if (s[0] == 'B') Ans -= num;
        else if (s[0] == 'R') {
            getchar();
            Ans += num * fun();
            getchar();
        } 
    }
    return Ans;
}

int main() {
    printf("%d\n", abs(fun()));
    return 0;
}