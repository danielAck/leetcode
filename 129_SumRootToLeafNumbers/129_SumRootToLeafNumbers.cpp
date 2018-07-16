 /**
 * 题目地址： https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/description/
 * 参考来源： https://blog.csdn.net/weixin_42130471/article/details/80516191
 * 解题思路： 1. 其实数学方面过去了就很好解，主要理解 (temp+root->val)*10) 的作用
 */
 
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root==NULL)return 0;
        int ans=0,temp=0;
        dfs(root,ans,temp);
        return ans;
    }
    void dfs(TreeNode *root,int&ans,int temp){
        if(!root->left&&!root->right){
            ans+=temp+root->val;
        }
        if(root->left)dfs(root->left,ans,(temp+root->val)*10);
        if(root->right)dfs(root->right,ans,(temp+root->val)*10);
    }
};