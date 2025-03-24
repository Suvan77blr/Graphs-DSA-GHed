
// 140325
/*
    Iterative DFS technique.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
    public: 
        vector<int> dfsTraversal(vector<vector<int> >& mp);
};

vector<int> Solution :: dfsTraversal(vector< vector<int> >& mp)
{
    int n = mp.size();
    vector<bool> visited (n+1 , false);
    vector<int> dfsRes;
    vector<int> dfsStack;

    int srcNode;
    cin >> srcNode;

    visited[srcNode] = true;
    dfsRes.push_back(srcNode);
    dfsStack.push_back(srcNode);

    int currNode;
    while(!dfsStack.empty())
    {   
        currNode = dfsStack.back();
        dfsStack.pop_back();

        for(const int neigh : mp[currNode]) {
            if(!visited[neigh]){
                visited[neigh] = true;
                dfsStack.push_back(neigh);
                dfsRes.push_back(neigh);
            }
        }
    }   

    return dfsRes;
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