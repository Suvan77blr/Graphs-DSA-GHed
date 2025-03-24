
// 240325
/*
    Prog09 - Distinct Islands.
*/
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#define pii pair<int, int>
using namespace std;

class Solution {
    public:
        int getDistinctIslandsCount(vector<vector<int>>& grid) {
            int count = 0;
            int n=grid.size(), m=grid[0].size();
            vector<vector<bool>> vis (n, vector<bool>(m, false));
            set<vector<pii>> distinctIslands;

            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                    if(!vis[i][j] && grid[i][j]){
                        distinctIslands.insert(bfsIslandFinder(grid, vis, i, j));
                    }
                }
            }

            return distinctIslands.size();
        }

        vector<pii> bfsIslandFinder (vector<vector<int>>& grid, vector<vector<bool>>& vis, int sr, int sc) {
            int n=grid.size(), m=grid[0].size();
            vis[sr][sc] = true;
            
            vector<pii> points;
            points.push_back({sr-sr, sc-sc});

            vector<pii> bfsQ;
            bfsQ.push_back({sr, sc});

            vector<pii> delta = {
                {-1, 0}, {0, 1}, {1, 0}, {0, -1}
            };

            int nX, nY;
            while(!bfsQ.empty()) {
                auto [currX, currY] = bfsQ.back();
                bfsQ.pop_back();

                for(const auto& [delX, delY] : delta) {
                    nX = currX + delX;
                    nY = currY + delY;

                    if(nX>=0 && nY>=0 && nX<n && nY<m && !vis[nX][nY] && grid[nX][nY]) {
                        vis[nX][nY] = true;
                        bfsQ.insert(bfsQ.begin(), {nX, nY});
                        points.push_back({nX-sr, nY-sc});
                    }
                }
            }
            return points;
        }
};

int main(void)
{
    int n, m;
    // cout << "Enter the vertex-count : ";
    cin >> n >> m;

    vector< vector<int> > adjMat (n, vector<int>(m, 0));
    // cout << "Enter the " << n <<"x" << n << " AdjMat : " << endl;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> adjMat[i][j];
        }   
    }

    // Printing the AdjMat... for confimation.
    cout << "Adjacency Matrix :-\n";
    for(const auto& row : adjMat)
    {
        for(const int ele : row)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

     // Calling the methods of Solution...to solve the problem.
    int distinctIslandCount = Solution().getDistinctIslandsCount(adjMat);
    cout << "Count of  Distinct Islands : " << distinctIslandCount << endl;

    return 0;
}