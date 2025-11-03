
// SafeStates => Nodes other than that part of cycle & connecting to a cycle.

#include <unordered_map>
using vi = vector<int>;
using vb = vector<bool>;
using graph = unordered_map<int, vi>;

// Checking via DFS call.
bool hasCycle(graph& g, vb& vis, vb& pathVis, vb& check, int node)
{
    vis[node] = true;
    pathVis[node] = true;
    check[node] = false;

    for(const int neigh: g[node])
    {
        if(!vis[neigh]) {
            if(hasCycle(g, vis, pathVis, neigh) == true)
            {
                check[node] = false;
                return true;
            }
        }
        // 'neigh' is visited.
        if(pathVis[neigh]) {
            check[node] = false;
            return true;
        }
    }

    check[node] = true;         // Node is safe node.
    pathVis[node] = false;
    return false;
}

vector<int> getAllSafeNodes(int n, vector < pair < int, int >> & edges) {
    graph g;
    int src, dest;
    for(auto edge: edges) {
      src=edge.first; dest=edge.second;
      g[src].push_back(dest);
    }

    vb vis(n+1, false);
    vb pathVis(n+1, false);
    vb check(n+1, false);

    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            hasCycle(g, vis, pathVis, check, i);
        }
    }

    vi safenodes;
    for(int i=1; i<=n; i++) {
        if(check[i]) safenodes.push_back(i);
    }
    return safenodes;
}