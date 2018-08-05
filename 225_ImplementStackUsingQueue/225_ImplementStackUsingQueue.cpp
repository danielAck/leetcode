 /**
 * 题目地址： https://leetcode-cn.com/problems/implement-stack-using-queues/description/
 * 解题思路： 1. 用两个队列实现，先将已经是栈形式的结果全部誊到备用队列中，将要push的值push进结果队列中
 *				 再把原来的结果依次push进结果队列, 时间 ：16ms
			  2. 只用一个队列就可以实现，相当于先把值push到最后，然后依次把前面的值放到队尾， 时间：12ms
 *    		  3. LeetCode中 0ms 的例程，不知道为什么同样的实现我的是 16ms
 */

 // 实现一
class MyStack {
public:
    queue<int> q1,q2;    

    MyStack() {
        
    }

    void push(int x) {
        if(q1.empty()){
            q1.push(x);
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        } else {
            q2.push(x);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
        }
    }

    int pop() {
        if(!q1.empty()){
            int temp = q1.front();
            q1.pop();
            return temp;
        } else {
            int temp = q2.front();
            q2.pop();
            return temp;
        }
    }

    int top() {
        return q1.empty()?q2.front():q1.front();
    }

    bool empty() {
        return (q1.empty()&&q2.empty());
    }
};


// 实现二 
 class MyStack {
public:
    queue<int> q1;  

    MyStack() {
        
    }

    void push(int x) {
        int n = q1.size();
        q1.push(x);
       while(n--){
           q1.push(q1.front());
           q1.pop();
       }
    }

    int pop() {
        int temp = q1.front();
        q1.pop();
        return temp;
    }

    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};


// 实现三
 class MyStack {
	 queue<int> Q;
 public:
	 MyStack() {

	 }

	 void push(int x) {
		 queue<int> revQ;
		 revQ.push(x);
		 while (!Q.empty()) {
			 revQ.push(Q.front());
			 Q.pop();
		 }
		 Q = revQ;
	 }

	 int pop() {
		 int ret = Q.front();
		 Q.pop();
		 return ret;
	 }

	 int top() {
		 return Q.front();
	 }

	 bool empty() {
		 return Q.empty();
	 }
 };