/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *  
 *   解法：使用递归算法，先判断两个树的结点值是否相同，然后递归判断两个树的左子树和右子树
 */
class Solution {
public:
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p && q) return false;
        else if(p && !q) return false;
        else{
            if(p->val != q->val) return false;
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};