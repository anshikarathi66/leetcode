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
    void solve(TreeNode* root, int targetSum, vector<int> temp, int &count){
        //base case
        if(root==NULL)
            return;
        
        temp.push_back(root->val);
        
        solve(root->left , targetSum, temp, count);
        solve(root->right, targetSum, temp, count);
        
        long int sum = 0;
        for(int i=temp.size()-1;i>=0;i--){
            sum+=temp[i];
            if(sum == targetSum)
                count++;
        }
        
        temp.pop_back();
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        int count=0;
        
        solve(root, targetSum, temp, count);
        return count;
    }
};