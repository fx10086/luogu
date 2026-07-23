#include <bits/stdc++.h>
using namespace std;

int a[12] = {0, 1, 2, 5, 11, 23, 47, 95, 191, 383, 767, 1535};
char pic[805][1605];
bool tr[1050];
int m, n;

void draw(int, int, int, int);

void drawl(int p, int n, int x, int y) {
    int i = x, j = y, tmp = a[n];
    while (tmp--) {
        i++, j--;
        pic[i][j] = '/';
    }
    i++, j--;
    pic[i][j] = 'o';
    draw(p, n - 1, i, j);
}

void drawr(int p, int n, int x, int y) {
    int i = x, j = y, tmp = a[n];
    while (tmp--) {
        i++, j++;
        pic[i][j] = '\\';
    }
    i++, j++;
    pic[i][j] = 'o';
    draw(p, n - 1, i, j);
}

void draw(int p, int n, int x, int y) {
    if (n == 0) return;
    if (tr[p * 2]) {
        drawl(p * 2, n, x, y);
    }
    if (tr[p * 2 + 1]) {
        drawr(p * 2 + 1, n, x, y);
    }
}

int main() {
    memset(pic, ' ', sizeof(pic));
    cin >> m >> n;
    for (int i = 1; i < (1 << m); ++i) {
        tr[i] = 1;
    }
    while (n--) {
        int i, j;
        cin >> i >> j;
        int tmp = (1 << (i - 1)) - 1;
        tmp += j;
        tr[tmp] = 0;
    }
    pic[1][a[m] + 1] = 'o';
    draw(1, m - 1, 1, a[m] + 1);
    for (int i = 1; i <= a[m] + 1; ++i) {
        for (int j = 1; j <= a[m + 1] + 1; ++j) {
            cout << pic[i][j];
        }
        cout << '\n';
    }
    return 0;
}