 /**
 * 题目地址： https://leetcode-cn.com/problems/find-bottom-left-tree-value/description/
 * 解题思路： 1. 先将右子节点入队，然后将左子节点入队，这样最后出队的时候最后出队的就是最左边的结点
 * 			  2. 按正常遍历最后出队的是最右边的结点
 */

// 精简的遍历队列方法
class Solution {
    public:
        int findBottomLeftValue(TreeNode *root) {
            queue<TreeNode *> q;
            q.push(root);
            
            while (!q.empty()) {
                root = q.front();
                if (root->right) { q.push(root->right); }
                if (root->left) { q.push(root->left); }
                q.pop();
            }
            return root->val;
        }
};

// 自己的代码
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        int res;
        int current,children;
        current = children = 0;
        q.push(root);
        current++;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            current--;
            if(children == 0){
                res = temp->val;
            }
            if(temp->right){
                q.push(temp->right);
                children++;
            }
            if(temp->left){
                q.push(temp->left);
                children++;
            }  
            if(current == 0){
                current = children;
                children = 0;
            }   
        }
        return res;
    }
};