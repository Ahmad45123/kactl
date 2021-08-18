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

const int N = 2e5+5;

vector<vector<int>> v;
int dfs_num[N], inSCC[N], dfs_low[N];
int counter, SCC;
stack<int> st;
int n;

void tarjanSCC(int u){
    dfs_low[u] = dfs_num[u] = ++counter;
    st.push(u);
    for(auto x : v[u]){
        if(!dfs_num[x])
            tarjanSCC(x);
        if(!inSCC[x])
            dfs_low[u] = min(dfs_low[x], dfs_low[u]);
    }
    if(dfs_num[u] == dfs_low[u]){
        SCC++;
        int x = -1;
        do{
            x = st.top(); st.pop();
            inSCC[x]=1;
        }while(u != x);
    }
}

void tarjanSCC(){
    for(int i=0; i<n; i++)
        if(!dfs_num[i])
            tarjanSCC(i);
}

void _clear(){
    v.clear();
    for(int i=0; i<n; i++){
        dfs_low[i]=0;
        dfs_num[i]=0;
        inSCC[i]=0;
        counter = 0;
        SCC=0;
    }
}