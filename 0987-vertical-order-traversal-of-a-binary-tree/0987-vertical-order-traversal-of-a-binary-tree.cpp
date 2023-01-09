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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //Need Two Data Structures : 
        //Map(keep track of HD and levelwiseNode(map)) , Queue(for level order traversal)
        
        map<int , map< int ,multiset<int> > > nodes;
        queue<pair<TreeNode*, pair<int , int> > > q;
        vector<vector<int>> ans;
        
        if(root == NULL)
            return ans;
        
        q.push(make_pair(root,make_pair(0,0)));
        
        
        while(!q.empty()){
            //take front entry from queue
            pair<TreeNode*, pair<int , int> > temp = q.front();
            q.pop();
            
            //take hd,node,level from temp
            TreeNode* firstnode = temp.first;
            int hd = temp.second.first;
            int lvl =temp.second.second;
            
            //update map
            nodes[hd][lvl].insert(firstnode->val);  
            
            //iterate further
            if(firstnode->left)
                q.push(make_pair(firstnode->left, make_pair(hd-1,lvl+1)));
            if(firstnode->right)
                q.push(make_pair(firstnode->right, make_pair(hd+1,lvl+1)));
            
        }
        
        //getting info required from map
        int prevlvl=-1;
        for(auto i:nodes){
            vector<int> v;
            for(auto j:i.second){
                v.insert(v.end(),j.second.begin(),j.second.end());
            }
            
            ans.push_back(v);
        }
        
        return ans;
    }
};