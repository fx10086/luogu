#include <bits/stdc++.h>
using namespace std;

int N, a, b;
const int M = 10000;
struct Server{
    int l, r;
    bool operator < (const Server &oth) const {
        return (l * r) < (oth.l * oth.r) || (l * r == oth.l * oth.r && l< oth.l);
    }
}A[1005];

struct high{
    int num[5005], len;
    high operator = (int oth) {
        len = 0;
        if (oth == 0) 
            len = 1, num[len] = 0;
        else 
            while (oth) {
                num[++len] = oth % M;
                oth /= M;
            }
        return *this;
    }
    high operator = (const high oth) {
        for (int i = 1; i <= oth.len; i++)
            num[i] = oth.num[i];
        len = oth.len;
        return *this;
    }
    void operator *= (const int oth) {
        for (int i = 1; i <= len; i++)
            num[i] *= oth;
        for (int i = 1; i <= len; i++) {
            num[i + 1] += num[i] / M;
            num[i] %= M;
            if (num[i + 1] && i >= len) 
                len++;
        }
    }
    high operator / (const int oth) {
        high c = *this;
        for (int i = c.len; i > 0; i--) {
            c.num[i - 1] += (c.num[i] % oth) * M;
            c.num[i] /= oth;
        } c.num[0] = 0;
        while (!c.num[c.len] && c.len) c.len--;
        if (!c.len) c.len++;
        return c;
    }
    bool operator > (const high &oth) const {
        if (len != oth.len) return len > oth.len;
        else 
            for (int i = len; i > 0; i--) 
                if (num[i] != oth.num[i])
                    return num[i] > oth.num[i];
        return false;
    }
    void Pr() {
        printf("%d", num[len]);
        for (int i = len - 1; i > 0; i--) 
            printf("%04d", num[i]);
        puts("");
    }
}Mul, Ans, Cal;

int main() {
    scanf("%d%d%d", &N, &a, &b);
    for (int i = 1; i <= N; i++)
        scanf("%d%d", &A[i].l, &A[i].r); 
    sort(A + 1, A + N + 1);
    
    // for (int i = 1; i <= N; i++)
    //     printf("l:%d r:%d\n", A[i].l, A[i].r);

    Mul = a;
    for (int i = 1; i <= N; i++) {
        Cal = Mul / A[i].r;
        // Cal.Pr();
        if (Cal > Ans) Ans = Cal;
        Mul *= A[i].l;
    }
    Ans.Pr();
    return 0;
}