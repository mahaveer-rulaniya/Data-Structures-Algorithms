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
    int search(vector<int> &inorder , int start , int end , int curr){
        for(int i=start;i<=end;i++){
            if(inorder[i]==curr) return i;
        }
        
        return -1;
    }
    
    TreeNode* Tree(vector<int> &preorder ,vector<int>&inorder, int start , int end ,int &idx){
        
        if(start>end) return NULL;
        
        int curr = preorder[idx];
        idx++;
        TreeNode* node = new TreeNode(curr);
        
        if(start==end) return node;
        
        int pos = search(inorder , start , end , curr);
        
        node->left = Tree(preorder, inorder , start , pos-1 , idx);
        node->right = Tree(preorder , inorder , pos+1 , end , idx);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return Tree(preorder , inorder , 0 , inorder.size()-1 , idx);
    }
};