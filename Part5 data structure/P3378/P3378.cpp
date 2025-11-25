#include <bits/stdc++.h>
using namespace std;

int N, op, x;
int head[1000005], siz;

void Ins(int x) {
    head[++siz] = x;
    int now = siz;
    while (now > 1) {
        int nxt = now >> 1;
        if (head[nxt] > head[now])
            swap(head[nxt], head[now]);
        else 
            break;
        now = nxt;
    }
}

void Del() {
    swap(head[1], head[siz]), siz--;
    int now = 1;
    while ((now << 1) <= siz) {
        int nxt = now << 1;
        if (head[nxt + 1] < head[nxt] && nxt + 1 <= siz)
            nxt++;
        if (head[nxt] < head[now])
            swap(head[nxt], head[now]);
        else 
            break;
        now = nxt;
    }
}

int main() {
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &op);
        switch(op) {
            case 1:
                scanf("%d", &x);
                Ins(x); break;
            case 2:
                printf("%d\n", head[1]);
                break;
            case 3:
                Del(); break;
        }
    }
    return 0;
}