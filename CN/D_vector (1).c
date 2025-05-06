#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define INFINITY 999

int main() {
    int n, i, j, k;
    int cost[MAX_NODES][MAX_NODES];
    int dist[MAX_NODES][MAX_NODES];
    int next_hop[MAX_NODES][MAX_NODES];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (i != j && cost[i][j] == 0) {
                cost[i][j] = INFINITY;
            }
        }
    }


    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            dist[i][j] = cost[i][j];
            if (i != j && dist[i][j] != INFINITY) {
                next_hop[i][j] = j;
            } else {
                next_hop[i][j] = -1;
            }
        }
    }

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next_hop[i][j] = next_hop[i][k];
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("\nRouting Table for Node %d:\n", i);
        printf("Destination\tNext Hop\tCost\n");
        for (j = 0; j < n; j++) {
            if (i != j) {
                printf("%d\t\t%d\t\t%d\n", j, next_hop[i][j], dist[i][j]);
            }
        }
    }

    return 0;
}

