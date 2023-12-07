#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define amountOfVertices 10

int minDistance(int dist[], bool sptSet[]){
    int min = INT_MAX, min_index;

    for(int v = 0; v < amountOfVertices; v++){
        if(sptSet[v] == false && dist[v] <= min){
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSolution(int dist[]){
    printf("Vertice \t\t Distancia da origem (A)\n");

    for(int i = 0; i < amountOfVertices; i++){
        printf("%d \t\t\t\t %d\n", i, dist[i]);
    }
}


void dijkstra(int graph[amountOfVertices][amountOfVertices], int src){
    int dist[amountOfVertices];

    bool sptSet[amountOfVertices];

    for(int i = 0; i < amountOfVertices; i++){
        dist[i] = INT_MAX, sptSet[i] = false;
    }

    dist[src] = 0;

    for(int count = 0; count < amountOfVertices - 1; count++){
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for(int v = 0; v < amountOfVertices; v++){

            if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}


int main(){
    

    int graph[amountOfVertices][amountOfVertices]  =  {
        // A, O, S, N, L, B, I, G, C, H
        {0, 15, 0, 4, 0, 0, 0, 0, 0, 0},    // A
        {15, 0, 2, 0, 0, 0, 0, 0, 0, 0},    // O
        {0, 2, 0, 3, 4, 500, 0, 0, 0, 0},   // S
        {4, 0, 3, 0, 0, 0, 7, 0, 0, 0},     // N
        {0, 0, 4, 0, 0, 0, 0, 0, 0, 7},     // L
        {0, 0, 500, 0, 0, 0, 0, 0, 0, 0},   // B
        {0, 0, 0, 7, 0, 0, 0, 25, 0, 0},     // I
        {0, 0, 0, 0, 0, 0, 25, 0, 80, 0},     // G
        {0, 0, 0, 0, 0, 0, 0, 80, 0, 45},     // C
        {0, 0, 0, 0, 7, 0, 0, 0, 45, 0}      // H
       
    };
    
    // 0 = A
    // 1 = O
    // 2 = S
    // 3 = N
    // 4 = L
    // 5 = B
    // 6 = I
    // 7 = G
    // 8 = C
    // 9 = H

    dijkstra(graph, 0);
 
    return 0;
}
