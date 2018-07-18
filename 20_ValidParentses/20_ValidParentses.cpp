 /**
 * 题目地址： https://leetcode-cn.com/problems/valid-parentheses/description/
 * 解题思路： 1. 使用栈结构，来一个符号先不急着入栈，如果栈里有元素则与栈顶元素判断是否配对，若配对则将栈顶元素弹出，
 *   		  相当于消去这一对符号，如果不能配对则入栈，如果合格最后应该是栈空
 */
 
class Solution {
public:
    
    bool check(char c1, char c2){
        if(c1 == '(' && c2 == ')') return true;
        else if(c1 == '[' && c2 == ']') return true;
        else if(c1 == '{' && c2 == '}') return true;
        else return false;
    }
    
    bool isValid(string s) {
        stack<char> stack;
        int size = 0; // 如果使用 stack.size()会很耗时间，直接用一个变量判断栈元素个数
        for(int i = 0; i < s.size(); i++){
            if(i>0 && size && check(stack.top(), s[i])) {
                stack.pop();
                size--;
            }
            else {
                stack.push(s[i]);
                size++;
            }
        }
        return stack.empty();
    }
};