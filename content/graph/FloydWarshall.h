/**
 * Author: Simon Lindholm
 * Date: 2016-12-15
 * License: CC0
 * Source: http://en.wikipedia.org/wiki/Floyd–Warshall_algorithm
 * Description: Calculates all-pairs shortest path in a directed graph that might have negative edge weights.
 * Input is an distance matrix $m$, where $m[i][j] = \texttt{inf}$ if $i$ and $j$ are not adjacent.
 * As output, $m[i][j]$ is set to the shortest distance between $i$ and $j$, \texttt{inf} if no path, or \texttt{-inf} if the path goes through a negative-weight cycle.
 * Time: O(N^3)
 * Status: slightly tested
 */
#pragma once

const int N = 500, OO = 1e9;

int adjMat[N][N];
int parent[N][N];
int n;

void floyd(){  //O(V^3)
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(!adjMat[i][j] && i != j)adjMat[i][j] = OO;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            parent[i][j] = i;
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(adjMat[i][j] > adjMat[i][k] + adjMat[k][j]){
                    adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
                    parent[i][j] = parent[k][j];
                }
}

void printPath(int i, int j){
    if(i != j)printPath(i, parent[i][j]);
    cout << j << " ";
}
