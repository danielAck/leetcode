 /**
 * 题目地址： https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/description/
 * 解题思路： 1. 递归
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        else
            return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }
};