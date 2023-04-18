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
    void inorder(TreeNode* root, vector<int> &rslt){
        //base case
        if(root==NULL){
            return;
        }
        
        inorder(root->left,rslt);
        
        rslt.push_back(root->val);
        
        inorder(root->right, rslt);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> rslt;
        inorder(root, rslt);
        
        return rslt[k-1];
    }
};