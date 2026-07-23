#include <bits/stdc++.h>
using namespace std;

int N, M, cnt, min_len;
map<string, int> f;
map<string, bool> v;
string s[100005], t[100005];

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> t[i];
        v[t[i]] = true;
    }
    cin >> M;
    int L = 1;
    for (int i = 1; i <= M; ++i) {
        cin >> s[i];
        if (v[s[i]]) ++f[s[i]];
        if (f[s[i]] == 1) {
            ++cnt;
            min_len = i - L + 1;
        }
        while (L <= i) {
            if (!v[s[L]]) { ++L; continue; }
            if (f[s[L]] >= 2) { --f[s[L]]; ++L; continue; }
            break;
        }
        min_len = min(min_len, i - L + 1);
    }
    cout << cnt << '\n';
    cout << min_len << '\n';
    return 0;
}