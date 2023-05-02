//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCyclicBFS(unordered_map<int,bool> &visited, unordered_map<int,int> &parent, vector<int> adj[], int src){
        queue<int> q;
        q.push(src);
        
        visited[src] = 1;
        parent[src] = -1;
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            for(int i = 0 ; i < adj[frontNode].size() ; i++){
                if(!visited[adj[frontNode][i]]){
                    visited[adj[frontNode][i]] = 1;
                    parent[adj[frontNode][i]] = frontNode;
                    q.push(adj[frontNode][i]);
                }
                
                else if(parent[frontNode] != adj[frontNode][i]){
                    return true;
                }
            }
        }
         return false;
    }
    
    bool isCyclicDFS(unordered_map<int,bool> &visited, int parent, vector<int> adj[], int src){
        visited[src] = true;
        
        //for each connected call
        for(int i=0;i<adj[src].size();i++){
            if(!visited[adj[src][i]]){
                bool cycleDetected = isCyclicDFS(visited, src, adj, adj[src][i]);
                if(cycleDetected == true){
                    return true;
                }
            }
            else if(parent != adj[src][i]){
                return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        //data structure to store if visited
        unordered_map<int,bool> visited;
        
        //data strcuture to store parent
        unordered_map<int,int> parent;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                // bool ans = isCyclicBFS(visited, parent, adj, i);
                bool ans = isCyclicDFS(visited, -1, adj, i);
                if(ans){
                return true;
            }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends