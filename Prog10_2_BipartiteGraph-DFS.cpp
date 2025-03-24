
// 240325
/*
    Prog10_2 : Bipartite Graph Detection using DFS.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool dfsChecker(vector<vector<int>>& grid, vector<bool>& vis, vector<int>& color, int start){
            vis[start] = true;

            for(const int neigh : grid[start]) {
                if(!vis[neigh] && color[neigh] == -1){
                    color[neigh] = !color[start];
                    if(dfsChecker(grid, vis, color, neigh) == false)
                        return false;
                }
                if(color[neigh] == color[start]){
                    return false;
                }
            }
            return true;
        }
        
        bool checkBipartite(vector<vector<int>>& grid)
        {
            int m=grid.size(), n=grid[0].size();
            vector<bool> vis(m, false);

            vector<int> color(grid.size(), -1);

            for(int i=0; i<m; i++)
            {
                if(!vis[i]){
                    color[i] = 0;
                    vis[i] = true;
                    if((dfsChecker(grid, vis, color, i)) == false)
                        return false;
                }
            }
            return true;
        }
};

int main(void)
{
    int n, m;
    // cout << "Enter the vertex-count & edge-count : ";
    cin >> n >> m;

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

    // Calling the methods of Solution...to solve the problem.
    bool result = Solution().checkBipartite(adjList);
    cout << "Bipartite Graph? : ";
    cout << ( result ? "True.\n" : "False.\n");

    return 0;
}