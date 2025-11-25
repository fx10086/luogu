#include <bits/stdc++.h>
using namespace std;

string s;
stack<int> T;
int num;
int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9')
            num = num * 10 + (s[i] - '0');
        else if (s[i] == '.') {
            T.push(num);
            num = 0;
        } else if (s[i] != '@') {
            int a = T.top(); T.pop();
            int b = T.top(); T.pop();
            int c;
            if (s[i] == '+') c = b + a;
            if (s[i] == '-') c = b - a;
            if (s[i] == '*') c = b * a;
            if (s[i] == '/') c = b / a;
            T.push(c);
        } else {
            printf("%d\n", T.top());
            T.pop();
        }
    }
    return 0;
}