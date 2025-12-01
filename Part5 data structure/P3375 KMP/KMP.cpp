#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
char s1[MAXN], s2[MAXN];
int K[MAXN];

int main() {
    scanf("%s%s", s1 + 1, s2 + 1);
    int l1 = strlen(s1 + 1), l2 = strlen(s2 + 1);
    int j = 0;
    for (int i = 2; i <= l2; i++) {
        while (j && s2[j + 1] != s2[i])
            j = K[j];
        if (s2[i] == s2[j + 1])
            j++;
        K[i] = j;
    }
    j = 0;
    for (int i = 1; i <= l1; i++) {
        while (j && s2[j + 1] != s1[i])
            j = K[j];
        if (s2[j + 1] == s1[i])
            j++;
        if (j == l2) {
            printf("%d\n", i - j + 1);
            j = K[j];
        }
    }
    for (int i = 1; i <= l2; i++)
        printf("%d ", K[i]);
    return 0;
}