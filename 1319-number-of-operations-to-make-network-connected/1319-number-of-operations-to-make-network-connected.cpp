class Solution {
public:
    void dfs(int node, unordered_map<int,bool>& visited, unordered_map<int,list<int>>& adj){
        visited[node] = true;
        
        for(auto neighbors: adj[node]){
            if(!visited[neighbors]){
                dfs(neighbors, visited, adj);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n-1 > connections.size() ){
            return -1;
        }
        //number of connection to be rearranged = number of isolated computers
        //create adjacency list
        unordered_map<int, list<int>> adj;
        for(int i =0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        unordered_map<int,bool> visited;
        int isolated_count =0;
        for(int i = 0 ; i < n; i++){
            if(!visited[i]){
                isolated_count++;
                dfs(i, visited, adj);
            }
        }
        
        return isolated_count-1;
    }
};