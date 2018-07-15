 
 /**
 * 题目地址： https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
 * 解题思路： 1.常规二叉树前序遍历，递归实现 + 迭代实现
 */
 
 // 递归实现
class Solution {
public:
    
    void preorderT(TreeNode* root, vector<int>& res){
        if(!root) return;
        res.push_back(root->val);
        preorderT(root->left, res);
        preorderT(root->right, res);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorderT(root, res);
        return res;
    }
};

// 迭代实现
class Solution {
public:
    
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        if(!root) return res;
        s.push(root);
        while(!s.empty()){
            TreeNode* temp = s.top();
            s.pop();
            res.push_back(temp->val);
            if(temp->right) s.push(temp->right);
            if(temp->left) s.push(temp->left);
        }
        return res;
    }
};