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
    void solve(TreeNode* root, int targetSum,vector<vector<int>> &ans, int sum,vector<int> temp){
        //base case
        if(root == NULL)
            return;
        
        temp.push_back(root->val);
        sum+=root->val;
        
        solve(root->left, targetSum, ans, sum,temp);
        solve(root->right, targetSum, ans, sum, temp);
        
        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum){
                ans.push_back(temp);
            }
        }
        
        temp.pop_back();
        sum -= root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        int sum = 0;
        vector<int> temp;
        
        solve(root, targetSum, ans, sum, temp);
        return ans;
    }
};