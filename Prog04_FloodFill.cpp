
// 150325
/*
    Prog04 : Flood Fill algorithm.
        => 4-adjacency.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& adjMat, int sr, int sc, int newColor);
        void bfsFilling(vector<vector<int>>& adjMat, vector<vector<int>>& res, vector<vector<bool>>& vis, int sr, int sc, int newColor);
};

vector<vector<int>> Solution :: floodFill(vector<vector<int>>& adjMat, int sr, int sc, int newColor)
{
    int n = adjMat.size(), m = adjMat[0].size();
    vector<vector<int>> res (adjMat);
    // static allocation not done.
    // bool vis[n][m] = {false};

    vector<vector<bool>> vis(n);
    for(int i=0; i<n; i++){
        vis[i] = vector<bool>(m, false);
    }

    // Initiate BFS from {sr, sc};
    bfsFilling(adjMat, res, vis, sr, sc, newColor);
    return adjMat;
}

void Solution :: bfsFilling(vector<vector<int>>& adjMat, vector<vector<int>>& res, vector<vector<bool>>& vis, int sr, int sc, int newColor)
{
    // cout << "\nBFS from (" << i << ", " << j << " )\n";
    int n = adjMat.size(), m = adjMat[0].size();
    int matchColor = adjMat[sr][sc];

    vis[sr][sc] = true;
    adjMat[sr][sc] = newColor;
    vector<pair<int, int>> bfsQueue;
    bfsQueue.push_back({sr, sc});

    // For 4-adjacency.
    vector<pair<int, int>> delta {
        {-1, +0}, {+0, +1}, {+1, +0}, {+0, -1},     // Cardinal-dir
    };

    int neigh_x, neigh_y;
    while(!bfsQueue.empty())
    {
        auto [new_x, new_y] = bfsQueue.back();
        bfsQueue.pop_back();

        for(int i=0; i<delta.size(); i++) {
            neigh_x = new_x + delta[i].first;
            neigh_y = new_y + delta[i].second;
    
            if(neigh_x >= 0 && neigh_y >= 0 && neigh_x < n && neigh_y < m)
            {
                if(adjMat[neigh_x][neigh_y]==matchColor && !vis[neigh_x][neigh_y])
                {
                    vis[neigh_x][neigh_y] = true;
                    adjMat[neigh_x][neigh_y] = newColor;
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

    int sr, sc;
    // cout << "Enter the src row & col : ";
    cin >> sr >> sc;

    int newColor;
    // cout << "Enter the newColor to flood-fill : ";
    cin >> newColor;

    // Printing the AdjMat... for confimation.
    cout << "Adjacency Matrix :-\n";
    for(const auto& row : adjMat) {
        for(const int ele : row) {
            cout << ele << " ";
        } cout << endl;
    }

    vector<vector<int>> result = Solution().floodFill(adjMat, sr, sc, newColor);

    cout << "\n\nFlood-Filled Matrix :-\n";
    for(const auto& row : adjMat) {
        for(const int ele : row) {
            cout << ele << " ";
        } cout << endl;
    }
    return 0;
}

/*
    TCs :
    1) IP : 3 3
            1 1 1 
            1 1 0 
            1 0 1
            1 1 2

       OP : 2 2 2 
            2 2 0 
            2 0 1 

    2) IP : 3 3
            1 0 1
            0 1 0
            1 0 1
            0 1 2
            
       OP : 1 2 1 
            0 2 0 
            1 0 1              

*/