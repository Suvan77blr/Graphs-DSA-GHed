
// 220325
/*
    Prog08_2 : Enclaved Regions 
        => Counting the number of interior land cells, those not connected to the boundary.

    Given is an mxn binary matrix 'grid', where;
        0 represents a sea cell and 1 represents a land cell.
    
    A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

    Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.    
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    int numEnclaves(vector<vector<int>>& grid);
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int sr, int sc, vector<pair<int, int>>& delta);
};

int Solution :: numEnclaves(vector<vector<int>>& grid) {
    int m=grid.size(), n=grid[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n, false));

    vector<pair<int, int>> delta = {
        {-1,0}, {0,1}, {1,0}, {0, -1}
    };

    for(int i=0; i<n; i++) {
        if(grid[0][i]==1 && !vis[0][i]) {
            dfs(grid, vis, 0, i, delta);
        }
        if(grid[m-1][i]==1 && !vis[m-1][i]){
            dfs(grid, vis, m-1, i, delta);
        }
    }

    for(int i=0; i<m; i++) {
        if(grid[i][0]==1 && !vis[i][0]){
            dfs(grid, vis, i, 0, delta);
        }
        if(grid[i][n-1]==1 && !vis[i][n-1]){
            dfs(grid, vis, i, n-1, delta);
        }
    }

    int interiorLandCount = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++) {
            if(grid[i][j]==1 && !vis[i][j])
                interiorLandCount++;
        }
    }      
    return interiorLandCount;
}

void Solution :: dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int sr, int sc, vector<pair<int, int>>& delta)
{
    vis[sr][sc] = true;
    int nX, nY;
    for(const auto del : delta) {
        nX = sr + del.first;
        nY = sc + del.second;

        if(nX>=0 && nY>=0 && nX<grid.size() && nY<grid[0].size() && !vis[nX][nY] && grid[nX][nY]=='O') {
            dfs(grid, vis, nX, nY, delta);
        }
    }
}

int main(void) {
    int n, m;
    // cout << "Enter the order of the nxm matrix : ";
    cin >> n >> m;

    vector< vector<int> > grid (n, vector<int>(m));
    // cout << "Enter the " << n <<"x" << n << " grid : " << endl;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
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

    // Calling the methods of Solution...to numEnclaves the problem.
    int countEnclaves = Solution().numEnclaves(grid);

    cout << "\nNumber of Enclaves : " << countEnclaves << endl;
    return 0;
}

/*
    TCs:
    1) IP : 4 4
            0 0 0 0
            1 0 1 0
            0 1 1 0
            0 0 0 0

    2) IP : 5 5
            X X X X X
            X O O X O
            X X O X O
            X O X O X
            O O X X X

*/