 /**
 * 题目地址： https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
 * 解题思路： 1. 跟102二叉树的层序遍历一个思路，只需要添加一个flag标记，反向插入一下就OK
 */
 

/**
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
    
    void fun(TreeNode* root, vector<vector<int>>& res, int n, int flag){
        if(!root) return;
        if(n >= res.size()){res.push_back(vector<int>());}
        if(flag == 1)
            res[n].push_back(root->val);
        else
            res[n].insert(res[n].begin(), root->val);
        fun(root->left, res, n+1, -flag);
        fun(root->right, res, n+1, -flag);
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        fun(root, res, 0, 1);
        return res;
    }
};