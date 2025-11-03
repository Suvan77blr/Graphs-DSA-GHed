
// Cycle detection using BFS. => create Topo sort using Kahn's.
//   => Check if resultant-sorting's length <N => invalid sort ... thus CYCLE!

#include <unordered_map>
#include <queue>
using vi = vector<int>;
using vb = vector<bool>;
using graph = unordered_map<int, vi>;

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  graph g;
  int src, dest;

  for(auto edge: edges) {
    src=edge.first; dest=edge.second;
    g[src].push_back(dest);
  }

  vi inDeg(n+1, 0);
  for(auto edge: edges) {
    inDeg[edge.second]++;
  }

  queue<int> q;
  for(int i=1; i<=n; i++) {
    if(inDeg[i] == 0)
    {
      q.push(i);
    }
  }

  vi ans;
  while(!q.empty()) {
    int curr = q.front();
    q.pop();
    ans.push_back(curr);
    for(const int neigh: g[curr]) {
      inDeg[neigh]--;
      if(inDeg[neigh]==0)
        q.push(neigh);
    }
  }
  return (ans.size() < n) ? true : false;
}