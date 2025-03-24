
// 150325
/*
    Program to find the number of provinces => no. of components of the graph.
    - Done w/ both BFS & DFS.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int getProvincesCount(vector<vector<int>>& adj);
        void bfs(vector< vector<int>>& adjList,  bool * vis, int srcNode );
        void dfs(vector< vector<int>>& adjList, bool * vis, int currNode);
};

int Solution :: getProvincesCount(vector<vector<int>>& adj)
{
    int n = adj.size();
    bool vis[n+1] = {false};

    int provCount = 0;
    for(int i=1; i<n; i++) {
        if(!vis[i]){
            dfs(adj, vis, i);
            provCount++;
        }
    }
    return provCount;
}

int main(void)
{
    int n;          
    cin >> n;

    // 1-based graph.
    vector<vector<int>>adjMat;
    
    vector<int> row; int temp;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> temp;
            row.push_back(temp);
        }
        adjMat.push_back(row);
        row.clear();
    }

    for(int i=0; i<n; i++)
    {
        cout << "\'" << i+1 << "\' : ";
        for(int j=0; j<n; j++) {
            if(adjMat[i][j])
                cout << j+1 << " ";
        }
        cout << endl;
    }
    
    int provincesCount = Solution().getProvincesCount(adjMat);
    cout << "Provinces : " << provincesCount << endl;
    return 0;
}

void Solution :: bfs(vector<vector<int>>& adj, bool * vis, int srcNode)
{
    cout << "BFS initiated from " << srcNode << endl;
    vector<int> bfsQ;
    vis[srcNode] = true;
    bfsQ.push_back(srcNode);

    int curr;
    while(!bfsQ.empty())
    {
        curr = bfsQ.back();
        bfsQ.pop_back();

        // for(const int neigh : adj[curr]) {
        for(int i=0; i<adj[curr-1].size(); i++) {
            if(!vis[i+1] && adj[curr-1][i]) {
                vis[i+1] = true;
                bfsQ.push_back(i+1);
            }
        }
    }
}

void Solution :: dfs(vector<vector<int>>& adj, bool*  vis, int curr) {
    vis[curr] = true;

    for(int i=0; i<adj.size(); i++) {
        if(!vis[i+1] && adj[curr-1][i]) {
            dfs(adj, vis, i+1);
        }
    }
}

/*
    TCs :-
    1) IP : 
        8
        1 1 0 0 0 0 0 0 
        1 1 1 0 0 0 0 0 
        0 1 1 0 0 0 0 0 
        0 0 0 1 1 0 0 0 
        0 0 0 1 1 1 0 0 
        0 0 0 0 1 1 0 0 
        0 0 0 0 0 0 1 1 
        0 0 0 0 0 0 1 1 
       OP : 3
    
    2) IP : 3
            1 0 1
            0 1 0
            1 0 1
       OP : 2 
*/