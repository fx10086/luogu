#include <bits/stdc++.h>
using namespace std;

int T, L, n, F, E, cmp[26], X, Y, st, cnt, Ans;
char FE, zm;
string O, x, y;
stack<int> St;
bool flag;

int get_num(string a) {
    int ans = 0;
    if (a != "O(1)") {
        if (a == "n") ans = 101;
        else for (int i = 0; i < a.size(); i++)
            if (a[i] >= '0' && a[i] <= '9')
                ans = ans * 10 + a[i] - '0';
    }
    return ans;
}

int main() {
    // freopen("P3952.in", "r", stdin);
    // freopen("P3952.out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> L >> O;
        n = get_num(O), F = E = cnt = Ans = 0, flag = false;
        for (int i = 0; i < 26; i++)
            cmp[i] = 0;
        while (L--) {
            cin >> FE; st = 0;
            if (FE == 'F') {
                F++;
                cin >> zm >> x >> y;
                cmp[zm - 'a']++, X = get_num(x), Y = get_num(y);
                //  cout << X << " " << Y << " st:";
                if (cmp[zm - 'a'] > 1) {
                    flag = true;
                    continue;
                }
                if (X > Y) st = 1;
                else if (X < 101 && Y == 101) st = 2;
                if (St.size()) if (St.top() == 1) st = 1;
                if (st == 2) cnt++;
                St.push(st);
                // cout << st << endl;
            } else {
                E++;
                if (St.size()) {
                    if (St.top() == 2) cnt--;
                    St.pop();
                }
                for (int i = 0; i < 26; i++)
                    cmp[i] = 0;
            }
            Ans = max(Ans, cnt);
            if (F < E) {
                flag = true;
                continue;
            }
        }
        if (flag || F != E) printf("ERR\n"); 
        else if (Ans != n) printf("No\n");
        else printf("Yes\n");
        // cout << "Check: " << Ans << " " << n << endl;
    }
    return 0;
}