#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    if (scanf("%d%d", &n, &m) != 2) {
        perror("scanf");
        return 1;
    }

    int *arena = malloc(2 * sizeof(int) * n * m);
    if (arena == NULL) {
        perror("malloc");
        return 1;
    }
    int *table = arena;
    int *dp = arena + n * m;

    for (int i = 0; i < n * m; i++)
        if (scanf("%d", &arena[i]) != 1) {
            perror("scanf");
            free(arena);
            return 1;
        }

    dp[0] = table[0];
    for (int i = 1; i < m; i++)
        dp[i] = dp[i - 1] + table[i];
    for (int i = 1; i < n; i++)
        dp[i * m] = dp[(i - 1) * m] + table[i * m];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++) {
            int idx = i * m + j;
            int left = idx - 1;
            int above = idx - m;
            dp[idx] = dp[left] > dp[above] ? dp[left] : dp[above];
            dp[idx] += table[idx];
        }

    printf("%d\n", dp[n * m - 1]);

    int path_len = n + m - 2;
    int path_idx = path_len - 1;
    char *path = malloc(path_len);
    if (path == NULL) {
        perror("malloc");
        free(arena);
        return 1;
    }
    int row = n - 1, col = m - 1;
    while (row > 0 || col > 0) {
        int idx = row * m + col;
        if (row == 0) {
            path[path_idx--] = 'R';
            col--;
        } else if (col == 0) {
            path[path_idx--] = 'D';
            row--;
        } else {
            int left = idx - 1;
            int above = idx - m;
            if (dp[left] > dp[above]) {
                path[path_idx--] = 'R';
                col--;
            } else {
                path[path_idx--] = 'D';
                row--;
            }
        }
    }

    path_idx++;
    while (path_idx < path_len)
        printf("%c ", path[path_idx++]);
    putc('\n', stdout);

    free(arena);
    free(path);
    return 0;
}
