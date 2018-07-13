/**
 * 解法：递归思想，参数是两个需要判断的结点，
 * 如果两个结点值相同，递归判断左结点的左子树、右节点的右子树 和 左结点的右子树、右结点的左子树
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        return judge(root, root);
    }
    bool judge(TreeNode *l, TreeNode *r)
    {
        if(l == NULL && r == NULL)    return true;
        else if(l == NULL || r == NULL)    return false;
        else if(l->val == r->val)
            return judge(l->left, r->right) && judge(l->right, r->left);
        else return false;
    }
};