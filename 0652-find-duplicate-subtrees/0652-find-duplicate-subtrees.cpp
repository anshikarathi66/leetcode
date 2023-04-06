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
    string solve(TreeNode* root,  unordered_map<string, int>& mp,vector<TreeNode*>& rslt){
      //base case
        if(root==NULL){
            return "N";
        }
        
        string s = to_string(root->val) + ',' + solve(root->left, mp, rslt) + ',' + solve(root->right, mp, rslt);
        
        if(mp[s] == 1){
            rslt.push_back(root);
        }
            mp[s]++;
        
        return s;
    
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> mp;
        vector<TreeNode*> rslt;
        
        solve(root,mp,rslt);
        return rslt;
    }
};