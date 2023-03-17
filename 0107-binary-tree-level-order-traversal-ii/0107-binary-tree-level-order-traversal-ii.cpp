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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        else if(root->left==NULL && root->right==NULL){
            ans.push_back({root->val});
            return ans;
        }
        stack<int> s;
    
        q.push(root);
        q.push(NULL);
        
        s.push(INT_MIN);
  
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            
            if(temp == NULL){
                s.push(INT_MIN);
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{  
            s.push(temp->val);
            if(temp->right)
                q.push(temp->right);
            if(temp->left)
                q.push(temp->left);
            }
        }
    vector<int> t;
        s.pop();
        
        while(!s.empty()){
            if(s.top()==INT_MIN){
                ans.push_back(t);
                t.clear();
                s.pop();
            }
            else{
                t.push_back(s.top());
                s.pop();
            }
        }
    
        return ans;
    }
};