#include <bits/stdc++.h>
using namespace std;

int N, siz, a, Ans;
int head[10005];

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
    swap(head[siz], head[1]), siz--;
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
    for (int i = 1; i <= N; i++) {
        scanf("%d", &a);
        Ins(a);
    }

    for (int i = 1; i < N; i++) {
        int t1 = head[1]; Del();
        int t2 = head[1]; Del();
        Ins(t1 + t2);
        Ans += (t1 + t2);
    }

    printf("%d\n", Ans);
    return 0;
}