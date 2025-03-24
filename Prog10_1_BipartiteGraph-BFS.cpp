
// 220325
/*
    Prog10_1 : Bipartite Graph Detection using BFS.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    public:
        bool bfsChecker(vector<vector<int>>& grid, vector<bool>& vis, int start)
        {
            int m=grid.size(), n=grid[0].size();
            vis[start] = true;
            
            vector<int> color(m+1, -1);
            color[start] = 0;

            queue<int> bfsQ;
            bfsQ.push(start);

            int currNode;
            while(!bfsQ.empty())
            {
                currNode = bfsQ.front();
                bfsQ.pop();

                for(int neigh : grid[currNode]) {
                    if(color[neigh] == -1){
                        color[neigh] = !color[currNode];
                        vis[neigh] = true;
                        bfsQ.push(neigh);
                    }
                    else if(color[neigh] == color[currNode]) {
                        return false;
                    }
                }
            }
            return true;
        }

        bool checkBipartite(vector<vector<int>>& grid)
        {
            int m=grid.size(), n=grid[0].size();
            vector<bool> vis(m, false);

            for(int i=0; i<m; i++)
            {
                if(!vis[i]){
                    if((bfsChecker(grid, vis, i)) == false)
                        return false;
                }
            }
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