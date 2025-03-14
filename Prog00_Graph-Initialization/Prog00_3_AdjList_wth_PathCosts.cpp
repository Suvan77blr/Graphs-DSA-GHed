
// 130325
/*
    Prog00_2 - Graph Adjacency List (UnDirG)
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(void)
{
    int n, m;
    cout << "Enter the vertex-count & edge-count : ";
    cin >> n >> m;

    unordered_map< int, vector<pair<int, int> > > adjList;

    // Initializing each of the 'n' entries to repr empty vectors.
    for(int i=1; i<=n; i++){
        adjList[i] = vector<pair<int, int>>();
    }
    // cout << "Enter the " << m << " edges (vi, vj, cij) : " << endl;
    
    int a, b, c;
    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        adjList[a].push_back({b, c});
        adjList[b].push_back({a, c});
    }

    cout << "Adjacency List :-\n";
    for(int i=1; i<=n; i++)
    {
        cout << "Node \'" << i << "\' : [ ";
        for(const auto& ele : adjList[i])
        {
            cout << ele.first << "("<< ele.second << ")" << " ";
        }
        cout << "]\n";
    }
    return 0;
}