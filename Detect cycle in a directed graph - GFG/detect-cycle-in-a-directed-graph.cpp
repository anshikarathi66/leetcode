//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool myDFS(int node, vector<int> adj[], unordered_map<int,bool> &visited, unordered_map<int,bool> &dfsVisited){
        visited[node] = true;
        dfsVisited[node] = true;
        
        for(int i = 0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
                bool cycleDetected = myDFS(adj[node][i] , adj, visited, dfsVisited);
                if(cycleDetected){
                    return true;
                }
            }
            else if(dfsVisited[adj[node][i]]){
                return true;
            }
        }
        
        dfsVisited[node] = false;
        
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        unordered_map<int,bool> visited;
        unordered_map<int,bool> dfsVisited;
        
        for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            bool ans = myDFS(i, adj, visited, dfsVisited);
            if (ans) {
                return true;
            }
        }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends