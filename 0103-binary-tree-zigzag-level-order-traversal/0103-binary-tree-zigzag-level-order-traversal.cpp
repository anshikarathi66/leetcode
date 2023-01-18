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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        
        bool leftToRight = true;
        vector<vector<int>> outer;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> inner(size);
            
            //process level
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                
                //insertion into vector based on leftToRight variable
                int index = leftToRight? i : size-i-1;
                inner[index] = temp->val;
                
                //push children into queue
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            
            //change direction
            leftToRight = !leftToRight;
            
            //insert inner vector into outer
            outer.push_back(inner);
        }
        
        return outer;
    }
};