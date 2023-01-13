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
    void solve(TreeNode* root , int &sum, vector<int> num){
        //base case
        if(root == NULL){
            return;
        }
        
        num.push_back(root->val);
        
        solve(root->left , sum, num);
        solve(root->right , sum, num);
        
        if(root->left == NULL && root->right == NULL){ //leaf node
            int digits = 0;
            for(int i = 0 ; i<num.size() ; i++){
                digits = digits*10+num[i];
            }
            sum+=digits;
        }
        
        num.pop_back();
    }
    
    int sumNumbers(TreeNode* root) {
        int sum=0;
        vector<int> num;
        
        solve(root , sum, num);
        return sum;
    }
};