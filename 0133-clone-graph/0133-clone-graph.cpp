/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node, Node* copy, unordered_map<Node*,Node*> &visited){
        visited[node]=copy;
        
        for(auto i: node->neighbors){
            if(visited[i] == NULL){
                Node* newNode = new Node(i->val);
                (copy->neighbors).push_back(newNode);
                dfs(i,newNode,visited);
            }
            else{
                (copy->neighbors).push_back(visited[i]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        
        unordered_map<Node*,Node*> visited;
        
        //clone starting node
        Node* copy = new Node(node->val);
        dfs(node,copy,visited);
        return copy;
    }
};