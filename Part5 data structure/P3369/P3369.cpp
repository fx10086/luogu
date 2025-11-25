#include <bits/stdc++.h>
#define MAXN 100005
#define RAND 1000000009
using namespace std;

struct tree {
    int l, r, v, siz, rnd;
}T[MAXN << 1];

int root, cnt, x, y, z;

void Up(int rt) {
    T[rt].siz = (T[T[rt].l].siz + T[T[rt].r].siz + 1);
}

int Add(int v) {
    T[++cnt] = (tree){0, 0, v, 1, rand() % RAND};
    return cnt;
}

void Spl(int rt, int v, int &x, int &y) {
    if (!rt) {
        x = y = 0;
        return;
    }
    if (T[rt].v <= v) {
        x = rt;
        Spl(T[rt].r, v, T[rt].r, y);
    } else {
        y = rt;
        Spl(T[rt].l, v, x, T[rt].l);
    }
    Up(rt);
}

int Mge(int x, int y) {
    if (!x || !y) return x + y;
    if (T[x].rnd >= T[y].rnd){
        T[x].r = Mge(T[x].r, y);
        Up(x);
        return x;
    } else {
        T[y].l = Mge(x, T[y].l);
        Up(y);
        return y;
    }
}

void Ins(int v) {
    int Node = Add(v);
    Spl(root, v, x, y);
    x = Mge(x, Node);
    root = Mge(x, y);
}

void Del(int v) {
    Spl(root, v, x, z);
    Spl(x, v - 1, x, y);
    y = Mge(T[y].l, T[y].r);
    x = Mge(x, y);
    root = Mge(x, z);
}

void Rank(int v) {
    Spl(root, v - 1, x, y);
    printf("%d\n", T[x].siz + 1);
    root = Mge(x, y);
}

void Num(int rank) {
    int now = root;
    while (now) {
        if (T[T[now].l].siz + 1 == rank) 
            break;
        else {
            if (T[T[now].l].siz + 1 > rank) 
                now = T[now].l;
            else
                rank -= (T[T[now].l].siz + 1),
                now = T[now].r;
        }
    }
    printf("%d\n", T[now].v);
}

void Pre(int v) {
    Spl(root, v - 1, x, y);
    int now = x;
    while (T[now].r) now = T[now].r;
    printf("%d\n", T[now].v);
    root = Mge(x, y);
}

void Suc(int v) {
    Spl(root, v, x, y);
    int now = y;
    while (T[now].l) now = T[now].l;
    printf("%d\n", T[now].v);
    root = Mge(x, y);
}

int N, op, k;

int main() {
    srand((unsigned)time(NULL));
    scanf("%d", &N);
    while (N--) {
        scanf("%d%d", &op, &k);
        switch (op) {
            case 1: Ins(k); break;
            case 2: Del(k); break;
            case 3: Rank(k); break;
            case 4: Num(k); break;
            case 5: Pre(k); break;
            case 6: Suc(k); break;
        }
    }
    return 0;
}