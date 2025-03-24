
// 220325
/*
    Prog08_1 : Surrounded Regions 
        => Replacing surrounded 'O's with 'X's.

    Given is a 2D matrix consisting of 'O's and 'X's.
    'O' or the set of 'O's can be replaced by 'X's iff there are 'X's on all 4 sides.

    Replace the relevant 'O's and then print the matrix.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    void solve(vector<vector<char>>& board);
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, int sr, int sc, vector<pair<int, int>>& delta);
};

void Solution :: solve(vector<vector<char>>& board) {
    int m=board.size(), n=board[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n, false));

    vector<pair<int, int>> delta = {
        {-1,0}, {0,1}, {1,0}, {0, -1}
    };

    for(int i=0; i<n; i++) {
        if(board[0][i] == 'O' && !vis[0][i]) {
            dfs(board, vis, 0, i, delta);
        }
        if(board[m-1][i] == 'O' && !vis[m-1][i]){
            dfs(board, vis, m-1, i, delta);
        }
    }

    for(int i=0; i<m; i++) {
        if(board[i][0]=='O' && !vis[i][0]){
            dfs(board, vis, i, 0, delta);
        }
        if(board[i][n-1]=='O' && !vis[i][n-1]){
            dfs(board, vis, i, n-1, delta);
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++) {
            if(board[i][j]=='O' && !vis[i][j])
                board[i][j] = 'X';
        }
    }      
}

void Solution :: dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, int sr, int sc, vector<pair<int, int>>& delta)
{
    vis[sr][sc] = true;
    int nX, nY;
    for(const auto del : delta) {
        nX = sr + del.first;
        nY = sc + del.second;

        if(nX>=0 && nY>=0 && nX<board.size() && nY<board[0].size() && !vis[nX][nY] && board[nX][nY]=='O') {
            dfs(board, vis, nX, nY, delta);
        }
    }
}

int main(void) {
    int n, m;
    // cout << "Enter the order of the nxm matrix : ";
    cin >> n >> m;

    vector< vector<char> > board (n, vector<char>(m));
    // cout << "Enter the " << n <<"x" << n << " board : " << endl;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
        }   
    }

    // Printing the board... for confimation.
    cout << "Adjacency Matrix :-\n";
    for(const auto& row : board) {
        for(const char ele : row) {
            cout << ele << " ";
        }
        cout << endl;
    }

    // Calling the methods of Solution...to solve the problem.
    Solution().solve(board);

    cout << "\nResult Matrix :-\n";
    for(const auto& row : board) {
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