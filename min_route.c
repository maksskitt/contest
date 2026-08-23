#include <stdio.h>
#include <stdlib.h>

int bfs(const int *graph, int rowsz, int src, int dst) {
    const int *row = graph + rowsz * src;
    for (int i = 0; i < rowsz; i++) {
        if (row[i] && i == dst) {
            return 1;
        }
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        perror("scanf");
        return 1;
    }
    int graphsz = n * n;

    int *arena = malloc((graphsz + n) * sizeof(int));
    int *graph = arena, *met = graph + graphsz;
    if (arena == NULL) {
        perror("malloc");
        return 1;
    }

    for (int i = 0; i < graphsz; i++)
        if (scanf("%d", &graph[i]) != 1) {
            perror("scanf");
            free(arena);
            return 1;
        }

    int src, dst;
    if (scanf("%d%d", &src, &dst) != 2) {
        perror("scanf");
        free(arena);
        return 1;
    }
    src--, dst--;

    printf("%d\n", bfs(graph, n, src, dst));

    free(arena);
    return 0;
}
