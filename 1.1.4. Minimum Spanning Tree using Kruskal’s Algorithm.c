#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int find(int i, int parent[]) {
    while (parent[i] >= 0) {
        i = parent[i];
    }
    return i;
}


int uni(int i, int j, int parent[]) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

void kruskalMST(int **cost, int V) {

	int *parent = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        parent[i] = -1;
    }

    int edge_count = 0;
    int min_cost = 0;

  
    while (edge_count < V - 1) {
        int min_val = 9999;
        int u = -1, v = -1;

       
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                if (cost[i][j] < min_val) {
                    min_val = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        // If no edge is found, the graph is disconnected or fully processed
        if (u == -1 || v == -1) {
            break;
        }

        int root_u = find(u, parent);
        int root_v = find(v, parent);

        if (uni(root_u, root_v, parent)) {
            printf("Edge %d:(%d, %d) cost:%d\n", edge_count, u, v, min_val);
            min_cost += min_val;
            edge_count++;
        }

        cost[u][v] = cost[v][u] = 9999;
    }

    printf("Minimum cost= %d\n", min_cost);
    free(parent);
}

int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}