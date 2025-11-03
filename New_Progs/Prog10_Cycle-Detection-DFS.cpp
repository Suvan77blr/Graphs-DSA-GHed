
// Cycle Detection => using DFS.

#include <unordered_map>
using vi = vector<int>;
using vb = vector<bool>;
using graph = unordered_map<int, vi>;

// Checking via DFS call.
bool hasCycle(graph& g, vb& vis, vb& pathVis, int node)
{
    vis[node] = true;
    pathVis[node] = true;

    for(const int neigh: g[node])
    {
        if(!vis[neigh]) {
            if(hasCycle(g, vis, pathVis, neigh) == true)
                return true;
        }
        // 'neigh' is visited.
        if(pathVis[neigh]) {
            return true;
        }
    }
    pathVis[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    graph g;
    int src, dest;
    for(auto edge: edges) {
      src=edge.first; dest=edge.second;
      g[src].push_back(dest);
    }

    vb vis(n+1, false);
    vb pathVis(n+1, false);

    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            if(hasCycle(g, vis, pathVis, i) == true)
                return true;
        }
    }
    return false;
}