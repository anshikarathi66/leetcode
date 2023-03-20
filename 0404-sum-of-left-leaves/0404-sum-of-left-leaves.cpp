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
    int solve(TreeNode* root, bool isleft){
        //base case
        if(root==NULL){
            return 0;
        }
        
        if(root->left==NULL && root->right==NULL){
            if(isleft == false){
                return 0;
            }
            else{
                return root->val;
            }   
        }
        
        int sum = solve(root->left,true) + solve(root->right,false);
        
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        bool isleft = false;
        return solve(root,isleft);
    }
};