#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    if (scanf("%d%d", &n, &m) != 2) {
        fputs("scanf failed\n", stderr);
        return 1;
    }

    int *dp = calloc(n * m, sizeof(int));
    if (dp == NULL) {
        fputs("calloc failed\n", stderr);
        return 1;
    }

    dp[0] = 1;
    int row = 0;
    int col = 1;
    while (row < n) {
        int idx = row * m + col;
        if (row >= 1 && col >= 2)
            dp[idx] += dp[idx - m - 2];
        if (row >= 2 && col >= 1)
            dp[idx] += dp[idx - 2 * m - 1];
        col++;
        if (col >= m) {
            col = 0;
            row++;
        }
    }

    printf("%d\n", dp[n * m - 1]);
    free(dp);
    return 0;
}
