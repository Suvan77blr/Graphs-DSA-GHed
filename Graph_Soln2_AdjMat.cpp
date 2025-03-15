
// 150325
/*
    Graph Soln Template - ADJ-MATRIX approach.
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
    int n;
    // cout << "Enter the vertex-count : ";
    cin >> n;

    vector< vector<int> > adjMat (n, vector<int>(n, 0));
    // cout << "Enter the " << n <<"x" << n << " AdjMat : " << endl;
    
    // int a, b, c;
    // int x;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            // cin >> x;
            // adjMat[i][j] = x;
            cin >> adjMat[i][j];
        }   
    }

    // Printing the AdjMat... for confimation.
    cout << "Adjacency Matrix :-\n";
    for(const auto& row : adjMat)
    {
        for(const int ele : row)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

     // Calling the methods of Solution...to solve the problem.

    return 0;
}