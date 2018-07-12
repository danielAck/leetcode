// 会超出时间限制，可以借鉴思路
class Solution {
public:
    int numTrees(int n) {
        int num = 0;
        if( n == 0 || n == 1 )
            return 1;
        for( int i = 1; i <= n; i++ )
        {
            num += ( numTrees( i-1 ) * numTrees( n-i ) ); // n - i 其实相当于把 i+1 到 n 变成 1 到 n-i的情况，二者结果是等价的
        }
        return num;
    }
};

//过了的解法，用数组存储中间用到的结果就能解决时间问题
class Solution {
public:
    
    int f(int n, int *tem) {
        int num = 0;
        if( n == 0 || n == 1 ){
            tem[n] = 1;
            return 1;
        }
        for( int i = 1; i <= n; i++ )
        {
            int left,right;
            if(tem[i-1] != 0) left = tem[i-1];
            else{
                left = f(i-1, tem);
                tem[i-1] = left;
            }
            if(tem[n-i] != 0) right = tem[n-i];
            else{
                right = f(n-i, tem);
                tem[n-i] = right;
            }
            num += (left * right);
        }
        return num;
    }
    
    int numTrees(int n) {
        int tem[n] = {0};
        return f(n, tem);
    }
};