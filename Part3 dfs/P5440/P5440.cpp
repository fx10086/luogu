#include <bits/stdc++.h>
using namespace std;

int T, a, b, c, cnt; //ri yueri nianyueri
string s;

bool check(int x, int y, int z) {
    for (int i = 2; i * i <= x; i++) 
        if (!(x % i)) return false;
    for (int i = 2; i * i <= y; i++) 
        if (!(y % i)) return false;
    for (int i = 2; i * i <= z; i++) 
        if (!(z % i)) return false;
    // puts("YES");
    return true;
}

void Upd1(int pos, int num) {
    if (pos >= 6) {
        a = a * 10 + num;
        b = b * 10 + num;
        c = c * 10 + num;
    } else if (pos >= 4) {
        b = b * 10 + num;
        c = c * 10 + num;
    } else c = c * 10 + num;
}

void Upd2(int pos) {
    if (pos >= 6) a /= 10, b /= 10, c /= 10;
    else if (pos >= 4) b /= 10, c /= 10;
    else c /= 10;
}

void dfs(int pos) {
    // printf("pos:%d num:%d\n", pos, int(s[pos] - '0'));
    if (pos == 8) {
        // printf("a:%d b:%d c:%d\n", a, b, c);
        if ((a >= 1 && a <= 31) && (int(b / 100) >= 1 && int(b / 100) <= 12) && check(a, b, c))
            cnt++;
        return;
    }
    if (s[pos] == '-') {
        for (int i = 0; i <= 9; i++) 
            Upd1(pos, i), dfs(pos + 1), Upd2(pos);
    } else Upd1(pos, int(s[pos] - '0')), dfs(pos + 1), Upd2(pos);
}

int main() {
    scanf("%d", &T); 
    while (T--) {
        cin >> s; 
        // cout << s << endl;
        a = b = c = cnt = 0;
        dfs(0);
        printf("%d\n", cnt);
    }
    return 0;
}