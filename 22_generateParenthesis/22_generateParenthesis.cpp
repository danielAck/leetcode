 /**
 * 题目地址： https://leetcode-cn.com/problems/generate-parentheses/description/
 * 解题思路： 1. 思路是递归，然后考虑加不加左括号，优先先加左括号直到个数达到n
 *			  2. 然后递归返回(相当于不加左括号)，判断左括号个数是否大于右括号，是则加右括号
 *			  3. 当左右括号数量都等于n时，得到解
 */

class Solution {
public:
    
    void dfs(int left, int right, string temp, vector<string>& res, int n){
        if(left == n && right == n){
            res.push_back(temp);
            return;
        }
        if(left < n){
            dfs(left+1, right, temp + '(', res, n);
        }
        if(left > right){
            dfs(left, right+1, temp + ')', res, n);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n == 0)  return res;
        dfs(0, 0, "", res, n);
        return res;
    }
};