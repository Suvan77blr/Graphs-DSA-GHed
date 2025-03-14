
// 130325
/*
    Prog00_1 - Graph Adjacency Matrix (UnDirG)
*/
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n, m;
    cout << "Enter the vertex-count & edge-count : ";
    cin >> n >> m;

    vector< vector<int> > adjMat (n, vector<int>(n, 0));
    cout << "Enter the " << m << " edges (vi, vj, cij) : " << endl;
    
    int a, b, c;
    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        adjMat[a-1][b-1] = adjMat[b-1][a-1] = c;
    }

    cout << "Adjacency Matrix :-\n";
    for(const auto& row : adjMat)
    {
        for(const int ele : row)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}