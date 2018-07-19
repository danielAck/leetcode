 /**
 * 题目地址： https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 * 解题思路： 1. 使用了一个trick没有用队列，dfs的过程当中动态的在res中生成存储对应层的数组，最后逆序输出
 */

class Solution {
public:
    
    void fun(TreeNode* root, vector<vector<int>>& res, int n){
        if(!root) return;
        if(n >= res.size())  res.push_back(vector<int>(1,root->val));
        else
            res[n].push_back(root->val);
        fun(root->left, res, n + 1);
        fun(root->right, res, n + 1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> temp,res;
        fun(root, temp, 0);
        for(int i = temp.size()-1; i >= 0; i--){
            res.push_back(temp[i]);
        }
        return res;
    }
};