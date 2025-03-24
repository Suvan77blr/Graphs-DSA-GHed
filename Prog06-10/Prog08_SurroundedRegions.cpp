
// 220325
/*
    Prog08 : Surrounding Regions 
        => Replacing surrounded 'O's with 'X's.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    vector<vector<char>> surroundingRegions(vector<vector<char>>& grid);
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int sr, int sc, bool& surrded, vector<pair<int, int>>& delta);
};

vector<vector<char>> Solution :: surroundingRegions(vector<vector<char>>& grid) {
    int n=grid.size(), m=grid[0].size();
    /*
        vis = { 0-NotVisited, 1-Visited_X-Able, 2-Visited_Not-X-Able}
    */
    vector<vector<int>> vis (n, vector<int>(m, 0));
    bool surrded = true;
    vector<pair<int, int>> delta = {
        {-1,0}, {0,1}, {1, 0}, {0,-1}
    };

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            surrded = true;
            if(!vis[i][j] && grid[i][j] == 'O')
            {            
                dfs(grid, vis, i, j, surrded, delta);
                if(!surrded)
                    vis[i][j] = 2;
            }
        }
    }

    vector<vector<char>> result (grid);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(vis[i][j] == 1)
            {
                result[i][j] = 'X';
            }
        }
    }
    return result;
}

void Solution :: dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int sr, int sc, bool& surrded, vector<pair<int, int>>& delta) {
    // cout << "Running DFS from " << sr << ", " << sc << endl;
    vis[sr][sc] = 1;
    int nX, nY;
    for(auto del : delta)
    {
        nX = sr + del.first;
        nY = sc + del.second;

        if(nX>=0 && nY>=0 && nX<grid.size() && nY<grid[0].size() && !vis[nX][nY] && grid[nX][nY]=='O') {
            vis[nX][nY] = 1;
            if(surrded) {
                if(nX==0 || nY==0 || nX==grid.size()-1 || nY==grid[0].size()-1) {
                    surrded = false;
                }
            }
            dfs(grid, vis, nX, nY, surrded, delta);
            
            // If not surrounded, they will not be 'X-able' but will still be visited.
            if(!surrded) vis[nX][nY] = 2;
        }
    }
}

int main(void) {
    int n, m;
    // cout << "Enter the order of the nxm matrix : ";
    cin >> n >> m;

    vector< vector<char> > grid (n, vector<char>(m));
    // cout << "Enter the " << n <<"x" << n << " grid : " << endl;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
        }   
    }

    // Printing the grid... for confimation.
    cout << "Adjacency Matrix :-\n";
    for(const auto& row : grid) {
        for(const char ele : row) {
            cout << ele << " ";
        }
        cout << endl;
    }

    // Calling the methods of Solution...to solve the problem.
    vector<vector<char>> result = Solution().surroundingRegions(grid);

    cout << "\nResult Matrix :-\n";
    for(const auto& row : result) {
        for(const auto ele : row) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
    TCs:
    1) IP : 5 4
            X X X X
            X O X X
            X O O X
            X O X X
            X X O O

    2) IP : 5 5
            X X X X X
            X O O X O
            X X O X O
            X O X O X
            O O X X X

*/