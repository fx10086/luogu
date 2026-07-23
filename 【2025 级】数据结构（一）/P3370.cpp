#include <bits/stdc++.h>
using namespace std;

int cnt;
map<string, int>f;

int main() {
    int N;
    cin >> N;
    while (N--) {
        string s;
        cin >> s;
        if (!f[s]) 
            ++cnt, f[s] = 1;
    }
    printf("%d\n", cnt);
    return 0;
}