/**
 * Author: Lukas Polacek
 * Date: 2009-10-28
 * License: CC0
 * Source: Czech graph algorithms book, by Demel. (Tarjan's algorithm)
 * Description: Tarjan
 * Time: O(E + V)
 * Status: Bruteforce-tested for N <= 5
 */
#pragma once

const int N = 2e5+5, OO = 1e9;
vector<vector<pair<int,int>>> v(N); // {node, cost}
int n;

int dijkstra(int S, int T){
    int dis[N];
    for(int i=0; i<N; i++)dis[i] = OO;
    dis[S] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, S});
    while(pq.size()){
        auto x = pq.top();
        pq.pop();
        x.first*=-1;
        if(x.second == T)return dis[T];
        if(dis[x.second] < x.first)continue;
        for(auto h : v[x.second]){
            if(h.second + x.first < dis[h.first]){
                dis[h.first] = h.second + x.first;
                pq.push({-dis[h.first], h.first});
            }
        }
    }
    return -1;
}
