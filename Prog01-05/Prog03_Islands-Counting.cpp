
// 150325
/*
    Prog03 : Counting the number of Islands.
        => 8-adjacency.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int getIslandsCount(vector<vector<int>>& adjMat);
        void bfs(vector<vector<int>>& adjMat, vector<vector<bool>>& vis, int i, int j);
};

int Solution :: getIslandsCount(vector<vector<int>>& adjMat)
{
    int n = adjMat.size(), m = adjMat[0].size();
    int count = 0;

    // static allocation not done, as it will lead to the use of complex ptrs and manual alloc and dealloc of memory.
    // bool vis[n][m] = {false};

    vector<vector<bool>> vis(n);
    for(int i=0; i<n; i++){
        vis[i] = vector<bool>(m, false);
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            // Water.
            if(adjMat[i][j] == 0){
                continue;
            }

            // Land.
            else {
                if(!vis[i][j]){
                    count++;
                    bfs(adjMat, vis, i, j);
                }
                // else Already visited .. so continue.
            }
        }
    }
    return count;
}

void Solution :: bfs(vector<vector<int>>& adjMat, vector<vector<bool>>& vis, int i, int j)
{
    cout << "\nBFS from (" << i << ", " << j << " )\n";
    int n = adjMat.size(), m = adjMat[0].size();
    vis[i][j] = true;
    vector<pair<int, int>> bfsQueue;
    bfsQueue.push_back({i, j});

    // For 8-adjacency.
    vector<pair<int, int>> delta {
        {-1, +0}, {+0, +1}, {+1, +0}, {+0, -1},     // Cardinal-dir
        {-1, +1}, {+1, +1}, {+1, -1}, {-1, -1},     // Ordinal-dir
    };

    int neigh_x, neigh_y;
    while(!bfsQueue.empty())
    {
        auto [new_x, new_y] = bfsQueue.back();
        bfsQueue.pop_back();

        for(int i=0; i<delta.size(); i++) {
            neigh_x = new_x + delta[i].first;    // x[i]
            neigh_y = new_y + delta[i].second;      // y[i]
    
            if(neigh_x >= 0 && neigh_y >= 0 && neigh_x < n && neigh_y < m)
            {
                if(adjMat[neigh_x][neigh_y] && !vis[neigh_x][neigh_y])
                {
                    vis[neigh_x][neigh_y] = true;
                    bfsQueue.insert(bfsQueue.begin(), {neigh_x, neigh_y});
                    // bfsQueue.push_back({neigh_x, neigh_y});
                }
            }
            // else continue;
        } // end-for.
    } // end-while.
    return;
}

int main(void)
{
    int n, m;
    // cout << "Enter the order of the matrix : ";
    cin >> n >> m;

    vector< vector<int> > adjMat (n, vector<int>(m, 0));
    // cout << "Enter the " << n <<"x" << n << " AdjMat : " << endl;
    
    // int x;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            // cin >> x;
            // adjMat[i][j] = x;
            cin >> adjMat[i][j];
        }   
    }

    // Printing the AdjMat... for confimation.
    cout << "Adjacency Matrix :-\n";
    for(const auto& row : adjMat) {
        for(const int ele : row) {
            cout << ele << " ";
        } cout << endl;
    }

    int islandsCount = Solution().getIslandsCount(adjMat);
    cout << "Island Count : " << islandsCount << endl;
    return 0;
}

/*
    TCs :
    1) IP : 5 4
            0 1 1 0
            0 1 1 0
            0 0 1 0
            0 0 0 0
            1 1 0 1
       OP : 3

    2) IP : 3 3
            1 0 1
            0 1 0
            1 0 1
       OP : 1              

*/