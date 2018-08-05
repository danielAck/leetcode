 /**
 * 题目地址： https://leetcode-cn.com/problems/implement-queue-using-stacks/description/
 * 解题思路： 1. 用两个栈实现，其中一个栈储存队列结果，另一个栈作为工具
 *   		  实现方法：将已经是队列形式的结果"倒"入工具中，将要push进的元素push到工具中，再原样"倒回"结果栈中
 *			  实现原理：将栈中的元素弹入到另一个栈内顺序刚好相反
 */

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        s1.push(x);
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int temp = s2.top();
        s2.pop();
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s2.empty();
    }
private:
    stack<int> s1,s2;
};