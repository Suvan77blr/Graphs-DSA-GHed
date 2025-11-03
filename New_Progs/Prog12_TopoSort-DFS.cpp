
// TopoSort using DFS => Stack.

#include <unordered_map>
#include <stack>
using vi = vector<int>;
using vb = vector<bool>;
using graph = unordered_map<int, vi>;

void dfs(graph& g, vb& vis, stack<int>& stk, int node)
{
	vis[node] = true;
	for(int neigh: g[node]) {
		if(!vis[neigh]) {
			dfs(g, vis, stk, neigh);
		}
	}
	stk.push(node);
}

vector<int> topologicalSort(vector<pair<int,int>>& edges, int N, int M)
{
	graph g;
	int src, dest;
	for(auto edge: edges)	 {
		src=edge.first; dest=edge.second;
		g[src].push_back(dest);
	}

	stack<int> stk;
	vb vis (N+1, false);

	for(int i=1; i<=N; i++) {
		if(!vis[i]) {
			dfs(g, vis, stk, i);
		}
	}

	vi result;
	while(!stk.empty()) {
		result.push_back(stk.top());
		stk.pop();
	}
	return result;
} 
