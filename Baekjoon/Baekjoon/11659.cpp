#include <stdio.h>
int N, M, temp;
int i, j;
int dp[100001] = {0, };
int main() {
    scanf("%d %d", &N, &M);
    for (int a = 1; a <= N; a++) {
        scanf("%d", &temp);
        dp[a] = dp[a - 1] + temp;
    }
    for (int a = 0; a < M; a++) {
        scanf("%d %d", &i, &j);
        printf("%d\n", dp[j] - dp[i - 1]);
    }
}