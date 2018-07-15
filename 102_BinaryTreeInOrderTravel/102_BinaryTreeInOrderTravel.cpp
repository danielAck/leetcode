 
 /**
 * 题目地址： https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 * 解题思路： 1.使用队列进行层序遍历，加两个检测变量 current children，
 *              current负责检测当前层还剩几个没有输出，children负责记录下一层的个数
 *            2.只用一个变量n代表应该存入的位置，然后进行DFS遍历每一个结点，每当访问子节点n+1
 */
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int current, children;
        current = children = 0;
        queue<TreeNode*> q;
        vector<vector<int>> res;
        vector<int> inner;
        if(!root) return res;
        q.push(root); current++;
        while(!q.empty()){
            TreeNode* tem = q.front();
            q.pop();    current--;
            inner.push_back(tem->val);
            if(current == 0){   //遍历完一层
                res.push_back(inner);
                //current = children; children = 0; 
                inner.clear(); //清空层存储数组
            } 
            if(tem->left){q.push(tem->left); children++;}
            if(tem->right){q.push(tem->right); children++;}
            if(current == 0){current = children; children = 0;}
        }
        
      return res;
    }
};


//解法二
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dp(ans,root,0);
        return ans;
    }
    
    void dp(vector<vector<int>>& ans,TreeNode* root,int n){
        if(root==NULL) return;
        if(ans.size()<=n) ans.push_back(vector<int>());
        ans[n].push_back(root->val);
        dp(ans,root->left,n+1);
        dp(ans,root->right,n+1);
    }
};