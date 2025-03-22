
// 210325
/*
    Prog07_1 : Distance of nearest Cell w/ 1
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> getMinDistOfOnes(vector<vector<int>>& grid)
        {
            int n=grid.size(), m=grid[0].size();

            vector<vector<bool>> vis(n, vector<bool>(m, false));

            vector<vector<int>> dist(n, vector<int>(m, 0));
            
            // [ .. {{i, j}, level} ...]
            vector< pair<pair<int, int>, int> > bfsQ;

            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                    if(grid[i][j] == 1) {
                        bfsQ.insert(bfsQ.begin(), {{i, j}, 0});
                    }
                }
            }

            vector<pair<int, int>> delta {
                {-1, 0}, {0, 1}, {1, 0}, {0, -1}
            };
            int nX, nY;

            while(!bfsQ.empty()){
                auto [crdinate, level] = bfsQ.back();
                auto [currX, currY] = crdinate;
                bfsQ.pop_back();

                dist[currX][currY] = level;

                for(const auto& del : delta){
                    nX = currX + del.first;
                    nY = currY + del.second;

                    if(nX>=0 && nY>=0 && nX<n && nY<m)
                    {
                        if(!vis[nX][nY] && grid[nX][nY] == 0) {
                            vis[nX][nY] = true;
                            bfsQ.insert(bfsQ.begin(), {{nX, nY}, level+1});
                        }
                    }
                }
            }
            return dist;
        }
};

int main(void) {
    int n, m;
    // cout << "Enter the order of the nxm matrix : ";
    cin >> n >> m;

    vector< vector<int> > grid (n, vector<int>(m, 0));
    // cout << "Enter the " << n <<"x" << n << " grid : " << endl;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }   
    }

    // Printing the grid... for confimation.
    cout << "Adjacency Matrix :-\n";
    for(const auto& row : grid) {
        for(const int ele : row) {
            cout << ele << " ";
        }
        cout << endl;
    }

    // Calling the methods of Solution...to solve the problem.
    vector<vector<int>> result = Solution().getMinDistOfOnes(grid);
    cout << "Matrix showing min dist of ones : " << endl;

    cout << "Distance Matrix :-\n";
    for(const auto& row : result) {
        for(const int ele : row) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
    TCs :
    1) IP : 3 3
            1 0 1
            1 1 0
            1 0 0
      OP : 0 1 0
           0 0 1
           0 1 2

    2) IP : 3 3
            0 0 0
            0 1 0
            1 0 1
      OP : 2 1 2
           1 0 1 
           0 1 0
*/