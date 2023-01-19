/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createMapping(TreeNode* root, int start, map<TreeNode*, TreeNode*>& nodeToParent){
        //use level order traversal to traverse the tree
        //find target node while traversing
        
        queue<TreeNode*> q;
        q.push(root);
        nodeToParent[root] = NULL;
        TreeNode* targetnode = NULL;
        
        while(!q.empty()){
            TreeNode* frontnode = q.front();
            q.pop();
            
            if(frontnode->val == start){
                targetnode = frontnode;
            }
            
            if(frontnode->left){
                nodeToParent[frontnode->left] = frontnode;
                q.push(frontnode->left);
            }
            if(frontnode->right){
                nodeToParent[frontnode->right] = frontnode;
                q.push(frontnode->right);
            }  
        }
        
        return targetnode;
    }
    
    int infect(TreeNode* root, TreeNode* target, map<TreeNode*, TreeNode*>& nodeToParent){
        //make a map to stores visited nodes and a queue for traversal
        map<TreeNode* , bool> visited;
        queue<TreeNode*> q;
        int time=0;
        
        //push target node since it is already burnt
        q.push(target);
        visited[target] = true;
        
        while(!q.empty()){
            int size = q.size(); //to traverse all the neighbouring nodes
            bool flag = false; //to know if something is inserted in queue or not
            
            for(int i=0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();
                
                if(front->left && !visited[front->left]){
                    flag = true;
                    q.push(front->left);
                    visited[front->left] = true;
                }
                if(front->right && !visited[front->right]){
                    flag = true;
                    q.push(front->right);
                    visited[front->right] = true;
                }
                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    flag=true;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                }
            }
            
            if(flag == true)
                time++;
        }
        
        return time;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        //create mapping of nodeToParent
        //find target node
        //calculate infecting time
        
        map<TreeNode*, TreeNode*> nodeToParent;
        TreeNode* target = createMapping(root, start, nodeToParent);
        int time = infect(root, target, nodeToParent);
        return time;
    }
};