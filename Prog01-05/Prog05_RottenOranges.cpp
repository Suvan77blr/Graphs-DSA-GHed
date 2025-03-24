
// 150325
/*
    Prog05 : Rotten Oranges.
        => special storing format [{r,c},t] & 4-adj.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        // Methods to solve the problem.
        int rottingOranges(vector<vector<int>>& grid);
};

int Solution :: rottingOranges(vector<vector<int>>& grid) {
    int n=grid.size(), m=grid[0].size();

    // [ {{row, col}, time}]
    vector<pair<pair<int, int>, int>> bfsQ;
    vector<vector<int>> vis (n, vector<int>(m, 0));

    int time = 0;

    int totalOrange=0, rotOrange=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 2){
                bfsQ.insert(bfsQ.begin(), {{i, j}, time});
                vis[i][j] = 2;
                rotOrange++;
            }
            if(grid[i][j] != 0){
                totalOrange++;
            }
        }
    }

    int delX[] = {-1, +0, +1, +0};
    int delY[] = {+0, +1, +0, -1};

    int nX, nY, t;
    while(!bfsQ.empty()) {
        auto [r, c] = bfsQ.back().first;
        t = bfsQ.back().second;
        time = max(t, time);
        bfsQ.pop_back();

        for(int i=0; i<4; i++)
        {
            nX = r + delX[i];
            nY = c + delY[i];

            if(nX>=0 && nY>=0 && nX<n && nY<m && (vis[nX][nY] != 2) && (grid[nX][nY]==1))
            {
                rotOrange++;
                bfsQ.insert(bfsQ.begin(), {{nX, nY}, t+1});
                vis[nX][nY] = 2;
            }
        }
    }
    if(rotOrange == totalOrange)
        return time;
    else return -1;
}

int main(void)
{
    int n, m;
    // cout << "Enter the vertex-count : ";
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
    int rottingTime = Solution().rottingOranges(grid);
    cout << "Time to rot all oranges : " << rottingTime << endl;
    return 0;
}

/*
    1) IP : 3 3
            2 1 1
            1 1 0
            0 1 1
       OP : 4 

    1) IP : 3 3
            1 2 1
            1 1 0 
            0 0 1
       OP : -1

    3) IP : 3 3
            0 1 2
            0 1 2
            2 1 1
       OP : 1
     
*/
