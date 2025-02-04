/**
 * Author: Lukas Polacek
 * Date: 2009-10-28
 * License: CC0
 * Description: Main function is find\_bridges; it performs necessary initialization and starts depth first search in each connected component of the graph.
Function `IS\_BRIDGE(a, b)` is some function that will process the fact that edge (a,b)(a,b) is a bridge, for example, print it.
Note that this implementation malfunctions if the graph has multiple edges, since it ignores them. Of course, multiple edges will never be a part of the answer, so IS\_BRIDGE can check additionally that the reported bridge is not a multiple edge. Alternatively it's possible to pass to dfs the index of the edge used to enter the vertex instead of the parent vertex (and store the indices of all vertices).
 * Time: O(N + M)
 */
#pragma once



int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}
