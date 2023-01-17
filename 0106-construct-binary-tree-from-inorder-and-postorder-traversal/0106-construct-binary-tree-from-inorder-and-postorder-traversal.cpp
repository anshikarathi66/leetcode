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
    TreeNode* solve(vector<int>& inorder,int inStart, int inEnd, vector<int>& postorder, int& index, int& n, unordered_map<int,int>& nodeToIndex){
        //base case
        if(index < 0 || inStart > inEnd)
            return NULL;
        
        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];
        
        //right called first because for second element it'll go first at right subtree
        root->right = solve(inorder, position+1, inEnd, postorder, index, n, nodeToIndex);
        root->left = solve(inorder, inStart, position-1, postorder, index, n, nodeToIndex);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> nodeToIndex;
        int n = postorder.size();
        for(int i=0;i<n;i++){
            nodeToIndex[inorder[i]]=i;
        }
        
        int index=n-1;
        
        return solve(inorder, 0, n-1, postorder, index, n, nodeToIndex);
        
    }
};