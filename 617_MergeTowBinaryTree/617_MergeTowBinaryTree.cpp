 /**
 * 题目地址： https://leetcode-cn.com/problems/merge-two-binary-trees/description/
 * 解题思路： 1.递归将t2合并到t1上
 * 			  2.重新生成一棵二叉树
 */
 
// 解法一
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL && t2 == NULL) return NULL;
        else if(t1 == NULL) return t2;
        else if(t2 == NULL) return t1;
        else {
            t1->val += t2->val;
            t1->left = mergeTrees(t1->left, t2->left);
            t1->right = mergeTrees(t1->right, t2->right);
            return t1;
        }
    }
};

// 解法二
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode *root=NULL;
        if (t1 == NULL && t2 == NULL)
            root = NULL;
        else if (t1 == NULL) {
            int val = t2->val;
            root = new TreeNode(t2->val);
            root->left = mergeTrees(NULL, t2->left);
            root->right = mergeTrees(NULL, t2->right);
        }
        else if (t2 == NULL) {
            int val = t1->val;
            root = new TreeNode(t1->val);
            root->left = mergeTrees(t1->left, NULL);
            root->right = mergeTrees(t1->right, NULL);
        }
        else {
            int val = t1->val + t2->val;
            root = new TreeNode(t1->val + t2->val);
            root->left = mergeTrees(t1->left, t2->left);
            root->right = mergeTrees(t1->right, t2->right);
        }
        return root;
    }
};