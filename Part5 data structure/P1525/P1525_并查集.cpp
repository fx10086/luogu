#include <bits/stdc++.h>
using namespace std;

int N, M;
int f[40005];

struct relation {
    int a, b, c;
    bool operator < (const relation &oth) const {
        return this->c > oth.c;
    }
}d[100005];

int Find (int x) {
    if (x == f[x]) return x;
    else return f[x] = Find(f[x]);
}

void Union(int x, int y) {
    int t1 = Find(x), t2 = Find(y);
    if (t1 != t2) f[t1] = t2;
}

bool Check(int x, int y) {
    int t1 = Find(x), t2 = Find(y);
    return t1 == t2;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; i++)
        scanf("%d%d%d", &d[i].a, &d[i].b, &d[i].c);
    for (int i = 0; i <= 2 * N; i++)
        f[i] = i;
    sort(d + 1, d + M + 1);

    for (int i = 1; i <= M + 1; i++) {
        if (Check(d[i].a, d[i].b)) {
            printf("%d\n", d[i].c);
            break;
        } else {
            Union(d[i].a, d[i].b + N);
            Union(d[i].b, d[i].a + N);
        }
    }
    return 0;
}