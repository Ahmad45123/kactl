/**
 * Author: Lukas Polacek
 * Date: 2009-10-26
 * License: CC0
 * Source: folklore
 * Description: Disjoint-set data structure.
 * Time: $O(\alpha(N))$
 */
#pragma once

const int N = 2e5+5;

int parent[N];
int setSize[N];
int rnk[N];

int findSet(int i){
    return parent[i] == i ? i : (parent[i] = findSet(parent[i]));
}

void unionSet(int i, int j){
    i = findSet(i), j = findSet(j);
    if(i == j)return;
    if(rnk[i] > rnk[j]){
        parent[j] = i;
        setSize[i] += setSize[j];
    }else{
        parent[i] = j;
        setSize[j] += setSize[i];
        if(rnk[j] == rnk[i])rnk[j]++;
    }
}

int main()
{
    for(int i=0; i<N; i++)parent[i] = i, setSize[i] = 1, rnk[i] = 0;
}