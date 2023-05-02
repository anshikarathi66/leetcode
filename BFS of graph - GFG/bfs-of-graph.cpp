//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(vector<int> adj[], int V, unordered_map<int,bool> &visited, vector<int> &ans, int node){
        //queue for traversinh all nodes and it's neighbours
        queue<int> q;
        
        //push first node
        q.push(node);
        
        
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            visited[frontNode] = 1;
            
            ans.push_back(frontNode);
            
            for(int col=0 ; col<adj[frontNode].size() ; col++){
                if(!visited[adj[frontNode][col]]){
                    q.push(adj[frontNode][col]);
                    visited[adj[frontNode][col]] = 1;
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        //to mark visited nodes
        unordered_map<int,bool> visited;
        
        //to store ans
        vector<int> ans;
        
        //call function
        bfs(adj, V, visited, ans , 0);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends