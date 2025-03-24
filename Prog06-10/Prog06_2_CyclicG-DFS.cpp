
// 210325
/*
    Prog06_2 : Cycle detection using DFS => UnDirGraph.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool dfsCycleDetection(vector< vector<int>>& adjList, vector<bool>& vis, int node, int parent)
        {
            vis[node] = true;

            for(const int neigh : adjList[node])
            {
                if(!vis[neigh])
                    return dfsCycleDetection(adjList, vis, neigh, node);
                
                else if(neigh != parent)
                    return true;   
            }
            return false;
        }

        bool hasCycle(vector< vector<int> >& adjList)
        {
            int n = adjList.size();
            int srcNode = 1;

            vector<bool> vis(n, false);

            return dfsCycleDetection(adjList, vis, srcNode, -1);
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
    
    int a,b;
    for(int i=0; i<m; i++) {
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

/*
    TCs :
    1) IP : 7 7
            1 2
            1 3
            2 5
            3 4
            3 6
            5 7
            6 7
       OP : True     
*/