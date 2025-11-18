#include <math.h>
#include <stdio.h>
using namespace std;

int N;
void div(int n) {
    for (int i = 14; i >= 0; i--) {
        if (int(pow(2, i)) <= n) {
            if (i == 1) printf("2");
            else if (i == 0) printf("2(0)");
            else {
                printf("2(");
                div(i);
                printf(")");
            }
            n -= pow(2, i);
            if (n) printf("+");
        }
    }
}

int main() {
    scanf("%d", &N);
    div(N);
    return 0;
}