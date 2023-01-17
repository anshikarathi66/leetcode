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
    void createmapping(vector<int> inorder, unordered_map<int,int>& nodeToIndex, int n){
        for(int i=0;i<n;i++){
            nodeToIndex[inorder[i]] = i;
        }
        
        return;
    }
    
    
    TreeNode* solve(vector<int> preorder, vector<int> inorder, unordered_map<int,int>& nodeToIndex, int n, int &index, int inOrderStart, int inOrderEnd){
        //base case
        if(inOrderStart > inOrderEnd || index >= n)
            return NULL;
        
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];
        
        root->left = solve(preorder, inorder, nodeToIndex, n, index, inOrderStart, position-1);
        root->right = solve(preorder, inorder, nodeToIndex, n, index, position+1, inOrderEnd);
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> nodeToIndex;
        int n = inorder.size();
        createmapping(inorder, nodeToIndex, n);
        int index=0;
        
        TreeNode* ans = solve(preorder, inorder, nodeToIndex, n, index, 0, n-1);
        return ans;
        
    }
};

// class Solution {
// public:
//     void createmapping(vector<int> inorder, unordered_map<int,int>& nodeToIndex, int n){
//         for(int i=0;i<n;i++){
//             nodeToIndex[inorder[i]] = i;
//         }
//         return;
//     }
    
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         unordered_map<int,int> nodeToIndex;
//         int n = inorder.size();
//         createmapping(inorder, nodeToIndex, n);
//         int index=0;
//         return solve(preorder, inorder, nodeToIndex, n, index, 0, n-1);
//     }
//     TreeNode* solve(vector<int> preorder, vector<int> inorder, unordered_map<int,int>& nodeToIndex, int n, int &index, int inOrderStart, int inOrderEnd){
//         //base case
//         if(inOrderStart > inOrderEnd || index >= n)
//             return NULL;
        
//         int element = preorder[index++];
//         TreeNode* root = new TreeNode(element);
//         int position = nodeToIndex[element];
        
//         root->left = solve(preorder, inorder, nodeToIndex, n, index, inOrderStart, position-1);
//         root->right = solve(preorder, inorder, nodeToIndex, n, index, position+1, inOrderEnd);
        
//         return root;
//     }
// };
