//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
// 	void dfstopo(int node, unordered_map<int,bool> &visited, stack<int> &s, vector<int> adj[]){
// 	    visited[node] = true;
	    
// 	    for(int i=0;i<adj[node].size();i++){
// 	        if(!visited[adj[node][i]]){
// 	            dfstopo(adj[node][i], visited, s ,adj);
// 	        }
// 	    }
	    
// 	    s.push(node);
// 	}
	
// 	vector<int> topoSort(int V, vector<int> adj[]) 
// 	{
// 	    // code here
// 	    unordered_map<int, bool> visited;
// 	    stack<int> s;
	    
// 	    for(int i =0;i<V;i++){
// 	        if(!visited[i]){
// 	            dfstopo(i,visited, s ,adj);
// 	        }
// 	    }
	    
// 	    vector<int> ans;
// 	    while(!s.empty()){
// 	        ans.push_back(s.top());
// 	        s.pop();
// 	    }
	    
// 	    return ans;
// 	}
	
	
	// **********USING KAHN'S ALGORITHM(BFS)**************
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	   
	    //calculate indegree
	    unordered_map<int,int> indegree;
	    
	    for(int i = 0 ; i < V ; i++){
	        for(int j =0;j<adj[i].size();j++){
	            indegree[adj[i][j]]++;
	        }
	    }
	    
	    //do bfs
	    vector<int> ans;
	    queue<int> q;
	    for(int i =0;i<V;i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    
	    while(!q.empty()){
	        int frontNode = q.front();
	        q.pop();
	        ans.push_back(frontNode);
	        
	        for(int neighbours = 0; neighbours < adj[frontNode].size() ; neighbours++){
	            indegree[adj[frontNode][neighbours]]--;
	            if(indegree[adj[frontNode][neighbours]] == 0){
	                q.push(adj[frontNode][neighbours]);
	            }
	        }
	    }
	    
	    return ans;
	}
	
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends