#include <stdio.h>
 
#include <limits.h>
 
 
 
int main() {
 
    int N, M;
 
    scanf("%d %d", &N, &M);
 
 
 
    int tamanhos[M];
 
    for (int i = 0; i < M; i++) {
 
        scanf("%d", &tamanhos[i]);
 
    }
 
 
 
    int dp[N+1];
 
 
 
    dp[0] = 0;
 
    for (int i = 1; i <= N; i++) {
 
        dp[i] = INT_MAX;
 
    }
 
 
 
    for (int i = 1; i <= N; i++) {
 
        for (int j = 0; j < M; j++) {
 
            int c = tamanhos[j];
 
            if (i - c >= 0 && dp[i - c] != INT_MAX) {
 
                if (dp[i - c] + 1 < dp[i]) {
 
                    dp[i] = dp[i - c] + 1;
 
                }
 
            }
 
        }
 
    }
 
 
 
    printf("%d\n", dp[N]);
 
    return 0;
 
}