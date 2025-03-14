
// 140325
/*
    BFS technique.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
    public: 
        vector<int> bfsTraversal(unordered_map< int, vector<int> >& mp);
};

vector<int> Solution :: bfsTraversal(unordered_map<int, vector<int> >& mp)
{
    int n = mp.size();
    vector<int> bfsQueue;
    vector<int> bfs;
    vector<bool> visited(n, false);
 
    int srcNode;
    cin >> srcNode;
 
    bfsQueue.push_back(srcNode);
    bfs.push_back(srcNode);
    visited[srcNode] = true;

    int currNode;
    while(bfsQueue.size() > 0) {
        currNode = bfsQueue.back();
        bfsQueue.pop_back();
        
        
        vector<int> neighbors = mp[currNode];
        for(const int neigh : neighbors)
        {
            if(!visited[neigh]){
                bfs.push_back(neigh);
                visited[neigh] = true;
                bfsQueue.insert(bfsQueue.begin(), neigh);
            }
        }
    }
    return bfs;
}

int main(void) {
    int n, q;
    cin >> n >> q;

    unordered_map< int, vector<int> > mp;
    for(int i=0; i<n; i++) {
        mp[i] = vector<int>();
    }

    // inputing the queries.
    int src, dest;
    for(int i=0; i<q; i++) {
        cin >> src >> dest;

        // Assuming UnDirGraph.
        mp[src].push_back(dest);
        mp[dest].push_back(src);
    }

    cout << "Adjacency List :-\n";
    for(int i=0; i<n; i++)
    {
        cout << "Node \'" << i << "\' : [ ";
        for(const auto& ele : mp[i])
        {
            cout << ele << " ";
        }
        cout << "]\n";
    }

    vector<int> bfs = Solution().bfsTraversal(mp);
    cout << "BFS : [ ";
    for(const int ele : bfs){
        cout << ele << " ";
    }
    cout << "]\n";
}