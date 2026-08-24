#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bfs(const int *adj_matrice, int *queue, int *dist, int rowsz, int src,
         int dst) {
    int front = 0, back = 0;

    queue[back++] = src;
    dist[src] = 0;
    while (front < back) {
        int parent = queue[front++];
        const int *row_has = adj_matrice + parent * rowsz;

        for (int child = 0; child < rowsz; child++)
            if (row_has[child] && dist[child] == -1) {
                dist[child] = dist[parent] + 1;
                queue[back++] = child;
                if (child == dst)
                    return; // time saving if found
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

    int *arena = malloc((graphsz + 2 * n) * sizeof(int));
    int *adj_matrice = arena, *queue = adj_matrice + graphsz, *dist = queue + n;
    if (arena == NULL) {
        perror("alloc");
        return 1;
    }
    memset(dist, -1, n * sizeof(*dist)); // make vertices unreachable by default

    for (int i = 0; i < graphsz; i++)
        if (scanf("%d", &adj_matrice[i]) != 1) {
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

    bfs(adj_matrice, queue, dist, n, src, dst);

    printf("%d\n", dist[dst]);

    free(arena);
    return 0;
}
