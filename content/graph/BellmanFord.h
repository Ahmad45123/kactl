/**
 * Author: Simon Lindholm
 * Date: 2015-02-23
 * License: CC0
 * Source: http://en.wikipedia.org/wiki/Bellman-Ford_algorithm
 * Description: Calculates shortest paths from $s$ in a graph that might have negative edge weights.
 * Unreachable nodes get dist = inf; nodes reachable through negative-weight cycles get dist = -inf.
 * Assumes $V^2 \max |w_i| < \tilde{} 2^{63}$.
 * Time: O(VE)
 * Status: Tested on kattis:shortestpath3
 */
#pragma once

bool bellmanFord(int S){ //O(V*E)
    int dis[N];
    for(int i=0; i<N; i++)dis[i] = OO;
    dis[S] = 0;
    bool modified = 1;
    for(int i=0; i<n-1 && modified; i++){
        modified = 0;
        for(int j=0; j<n; j++){
            for(auto h : v[j]){
                if(dis[j] + h.second < dis[h.first]){
                    dis[h.first] = dis[j] + h.second;
                    modified = 1;
                }
            }
        }
    }
    bool hasNegativeCycle = 0;
    for(int i = 0; i<n; i++)
        for(auto h : v[i])
            if(dis[i] + h.second < dis[h.first])
                hasNegativeCycle = 1;
    return hasNegativeCycle;
}

