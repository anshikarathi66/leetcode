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
    bool solve(TreeNode* left, TreeNode* right){
        //base case
        if(left == NULL && right == NULL)
            return true;
        else if(left!=NULL && right == NULL)
            return false;
        else if(left == NULL && right!=NULL)
            return false;
        
        bool left_ans = solve(left->left , right->right);
        bool right_ans = solve(left->right , right->left);
        
        if((left->val == right->val) && left_ans && right_ans)
            return true;
        else
            return false;
        
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root != NULL){
            return solve(root->left , root->right);
        }
        return false;
    }
};