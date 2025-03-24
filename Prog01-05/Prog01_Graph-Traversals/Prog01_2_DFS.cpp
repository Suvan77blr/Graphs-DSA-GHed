
// 140325
/*
    DFS technique.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
    public: 
        vector<int> dfsTraversal(vector<vector<int> >& mp);
        void dfs(vector<vector<int> > & mp, vector<bool>& visited, vector<int>& dfsRes, int currNode);
};

vector<int> Solution :: dfsTraversal(vector< vector<int> >& mp)
{
    int n = mp.size();
    vector<bool> visited (n+1 , false);

    int srcNode;
    cin >> srcNode;

    vector<int> dfsRes;
    
    dfs(mp, visited, dfsRes, srcNode);

    return dfsRes;
}

void Solution :: dfs(vector<vector<int> > & mp, vector<bool>& visited, vector<int>& dfsRes, int currNode)
{
    visited[currNode] = true;
    dfsRes.push_back(currNode);

    for(const int neigh : mp[currNode])
    {
        if(!visited[neigh]) {
            dfs(mp, visited, dfsRes, neigh);
        }
    }
}

int main(void) {
    int n, q;
    cin >> n >> q;

    vector< vector<int> > mp (n+1);
    for(int i=0; i<n; i++) {
        mp[i] = vector<int>();
    }

    // inputing the queries.
    int src, dest;
    for(int i=0; i<q; i++) {
        cin >> src >> dest;

        // Assuming UnDirGraph.
        mp[src].push_back(dest);
        mp[dest].push_back(src);
    }

    cout << "Adjacency List :-\n";
    for(int i=1; i<=n; i++)
    {
        cout << "Node \'" << i << "\' : [ ";
        for(const auto& ele : mp[i])
        {
            cout << ele << " ";
        }
        cout << "]\n";
    }

    vector<int> dfs = Solution().dfsTraversal(mp);
    cout << "dfs : [ ";
    for(const int ele : dfs){
        cout << ele << " ";
    }
    cout << "]\n";
}