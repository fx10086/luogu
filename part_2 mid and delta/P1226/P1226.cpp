#include <stdio.h>
using namespace std;

int a, b, p;
long long Ans = 1;
int main() {
    scanf("%d%d%d", &a, &b, &p);
    int c = b;
    long long q = a % p;
    while (b) {
        if (b & 1) 
            Ans = (Ans * q) % p;
        q = q * q % p, b >>= 1;
    }
    printf("%d^%d mod %d=%lld", a, c, p, Ans);
    return 0;
}