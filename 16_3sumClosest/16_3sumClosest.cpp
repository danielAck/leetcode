/*
 * 题目地址： https://leetcode-cn.com/problems/3sum-closest/description/
 * 解题思路： 1. 借助 3Sum 的思想，固定一个数，然后夹逼查找离target最近的数字，和直接查找一样
 *          2. 
 */

class Solution {
public:
    // 返回和target距离最小的值
    int min(int a, int b, int target){
        return abs(a-target) < abs(b-target)?a:b;
    }
    
    int threeSumClosest(vector<int>& num, int target) {
        sort(num.begin(),num.end());
        int n = num.size();
        int closest = num[0] + num[1] + num[n-1];               //保存最近的数字
        for(int i = 0; i < n; i++){                             //枚举a
            if(i && num[i] == num[i-1])     continue;           //排除重复的解
            int lhs = i+1,rhs = n-1;                            //b和c的下标
            while(rhs > lhs){                                   //O(n)枚举b和c
                 closest = min((num[i] + num[lhs] + num[rhs]),closest, target); 
                 if(rhs != n-1 && num[rhs] == num[rhs+1])   rhs--;              //排除重复的解
                 else if(lhs != i+1 && num[lhs] == num[lhs-1])      lhs++;      //排除重复的解
                 else if((num[i] + num[lhs] + num[rhs]) < target)   lhs++;             
                 else if((num[i] + num[lhs] + num[rhs]) > target)   rhs--;
                 else{
                     return target;
                 }
            }
        }
        return closest;
    }
};