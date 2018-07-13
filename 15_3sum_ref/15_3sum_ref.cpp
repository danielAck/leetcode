/*
 * 题目地址： https://leetcode-cn.com/problems/3sum/description/
 * 代码参考： https://github.com/gzwl/leetcode/blob/master/3Sum/3Sum.cpp?utm_source=qq&utm_medium=social&utm_oi=745026028811878400
 * 解题思路： 1. 使用 固定 和 夹逼 的思想，固定住第一个数 a， 使用两个指针指向数组的头和尾，计算出 b、c的值
 *          2. rhs 之后的都已经计算过了， lhs 之前的都已经计算过了
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        sort(num.begin(),num.end());                            //使数组有序
        vector<vector<int>> res;
        int n = num.size();
        if(n < 3)   return res;
        for(int i = 0; i < n; i++){                             //枚举 第一个数 a
            if(i && num[i] == num[i-1])     continue;           //排除重复的解，和之前计算过的情况重复且不是第一个元素
            int lhs = i+1,rhs = n-1;                            //b和c的下标
            while(rhs > lhs){                                   //O(n)枚举 b和 c
                 if(rhs != n-1 && num[rhs] == num[rhs+1])   rhs--;              //排除重复的解
                 else if(lhs != i+1 && num[lhs] == num[lhs-1])      lhs++;      //排除重复的解
                 else if(num[i] + num[lhs] + num[rhs] > 0)   rhs--;             
                 else if(num[i] + num[lhs] + num[rhs] < 0)   lhs++;
                 else{
                    res.push_back((vector<int>){num[i],num[lhs],num[rhs]});     //找到解
                    lhs++;
                    rhs--;
                 }
            }
        }
        return res;
    }
};