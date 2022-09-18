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
    vector<vector<int>> levelOrder(TreeNode* root) {
        TreeNode* curr = root;
        
        vector<vector<int>> res;
        if(root==NULL) return res;
        
        queue<TreeNode*> q;
        
        q.push(curr);
        res.push_back({curr->val});
        
        while(!q.empty()){
            vector<int> v;
            
            int n = q.size();
            
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left!=NULL){
                    q.push(temp->left);
                    v.push_back(temp->left->val);
                }

                if(temp->right !=NULL){
                    q.push(temp->right);
                    v.push_back(temp->right->val);
                }
            }
            
            if(v.size())
                res.push_back(v);
        }
        
        return res;
    }
};