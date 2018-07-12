/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //解法一，递归遍历
class Solution {
public:
    
    void travel(vector<int>& res, TreeNode* T){
        if(T->left != NULL) travel(res, T->left);
        res.push_back(T->val);
        if(T->right != NULL) travel(res, T->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        if(root == NULL) return res;
        travel(res, root);
        return res;
    }
};

//解法二，非递归中序遍历

