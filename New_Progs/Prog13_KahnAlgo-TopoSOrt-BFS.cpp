
// KahnAlgo => TopoSort using BFS. (inDegree)

#include <unordered_map>
#include <queue>
using vi = vector<int>;
using vb = vector<bool>;
using graph = unordered_map<int, vi>;

vector<int> topologicalSort(vector<pair<int,int>>& edges, int N, int M)
{
	graph g;
	int src, dest;
	
	for(auto edge: edges) {
		src=edge.first; dest=edge.second;
		g[src].push_back(dest);
	}

	vi inDeg (N+1, 0);
	for(auto edge: edges) {
		inDeg[edge.second]++;
	}
	
	queue<int> q;
	for(int i=1; i<=N; i++) {
		if(inDeg[i]==0)
		q.push(i);
	}

	vi ans;
	int curr;
	while(!q.empty()) {
		curr = q.front();
		q.pop();
		ans.push_back(curr);

		for(int neigh: g[curr]) {
			inDeg[neigh]--;
			if(inDeg[neigh] == 0) {
				q.push(neigh);
			}
		}
	}
	return ans;
} 
