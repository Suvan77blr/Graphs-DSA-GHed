
// 150325
/*
    Graph Soln Template - ADJ-LIST approach.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        // Methods to solve the problem.
};

int main(void)
{
    int n, m;
    // cout << "Enter the vertex-count & edge-count : ";
    cin >> n >> m;

    vector< vector<int> > adjList(n, vector<int>(m));

    // OR earlier initialization :-
    // vector< vector<int> > adjList(n);
    // Initializing each of the 'n' entries to repr empty vectors.
    // for(int i=1; i<=n; i++){
        // adjList[i] = vector<int>();
    // }
    // cout << "Enter the " << m << " edges (vi, vj, cij) : " << endl;
    
    // int a, b, c;
    int a,b;
    for(int i=0; i<m; i++) {
        // cin >> a >> b >> c;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    // Printing the AdjList... for confimation.
    cout << "Adjacency List :-\n";
    for(int i=1; i<=n; i++)
    {
        cout << "Node \'" << i << "\' : [ ";
        for(const auto& ele : adjList[i])
        {
            cout << ele << " ";
        }
        cout << "]\n";
    }

    // Calling the methods of Solution...to solve the problem.

    return 0;
}