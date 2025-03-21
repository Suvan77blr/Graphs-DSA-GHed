
// 180325
/*
    Prog06_1 : Cycle detection using BFS => UnDirGraph.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool hasCycle(vector< vector<int> >& adjList)
        {
            int n = adjList.size();
            int srcNode = 1;

            vector<pair<int, int>> bfsQ;
            // [ {currNode, parentNode}, ...]
            vector<bool> vis(n, false);
            // int currNode;

            vis[srcNode] = true;
            bfsQ.push_back({srcNode, -1});


            while(!bfsQ.empty())
            {
                auto [currNode, currParent] = bfsQ.back();
                bfsQ.pop_back();

                for(const int neigh : adjList[currNode])
                {
                    // Cycle detection...
                    if(vis[neigh] && neigh != currParent) {
                        return true;
                    }

                    if(!vis[neigh] && neigh!=currParent)
                    {
                        vis[neigh] = true;
                        bfsQ.insert(bfsQ.begin(), {neigh, currNode});
                    }
                }
            }
            return false;
        }
};

int main(void)
{
    int n, m;
    // cout << "Enter the vertex-count & edge-count : ";
    cin >> n >> m;

    // Considering a 1-based indexing graph.
    vector< vector<int> > adjList(n+1);

    // Initializing each of the 'n' entries to repr empty vectors.
    for(int i=1; i<=n; i++){
        adjList[i] = vector<int>();
    }
    // cout << "Enter the " << m << " edges (vi, vj, cij) : " << endl;
    
    // int a, b, c;
    int a,b;
    for(int i=0; i<m; i++) {
        // cin >> a >> b >> c;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    // Printing the AdjList... for confimation.
    cout << "Adjacency List :-\n";
    for(int i=1; i<=n; i++)
    {
        cout << "Node \'" << i << "\' : [ ";
        for(const auto& ele : adjList[i])
        {
            cout << ele << " ";
        }
        cout << "]\n";
    }

    bool result = Solution().hasCycle(adjList);
    cout << "Given graph has cycle? : ";
    cout << (result ? "true!\n" : "false!\n");

    return 0;
}