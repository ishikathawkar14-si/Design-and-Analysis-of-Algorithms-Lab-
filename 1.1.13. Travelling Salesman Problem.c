#include <stdio.h>
#include <stdbool.h>

#define INF 9999999
#define MAX_N 15

int n;
int costMatrix[MAX_N][MAX_N];
int minCost = INF;


void findTSP(int currentCity, int count, int currentCost, bool visited[], int startCity) {
    if (count == n) {
        if (costMatrix[currentCity][startCity] != -1) {
            int totalCost = currentCost + costMatrix[currentCity][startCity];
            if (totalCost < minCost) {
                minCost = totalCost;
            }
        }
        return;
    }

    for (int nextCity = 0; nextCity < n; nextCity++) {
        if (!visited[nextCity] && costMatrix[currentCity][nextCity] != -1) {
            visited[nextCity] = true;
            findTSP(nextCity, count + 1, currentCost + costMatrix[currentCity][nextCity], visited, startCity);

            visited[nextCity] = false;
        }
    }
}

int main() {
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    bool visited[MAX_N] = {false};
    

    visited[0] = true;
    findTSP(0, 1, 0, visited, 0);


    printf("%d\n", minCost);

     return 0;
}
