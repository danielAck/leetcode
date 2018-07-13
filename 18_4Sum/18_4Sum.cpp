/*
 * 题目地址： https://leetcode-cn.com/problems/4sum/description/
 * 解题思路： 1. 和 3Sum 一样，只不过多加一层循环，多固定一个数字
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > res;
        int n = nums.size();
        if(n < 4)   return res;
        for(int i = 0; i < n; i++){ //多一层判断                                         
            if(i && nums[i] == nums[i-1])     continue;

			//优化，剪枝判断
            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target)    break;	//数组最大和小于target,不存在最优解，直接返回空vector
            if(nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target)    continue;  //当前最大和小于target，剪枝，本轮不可能有解

            for(int j = i + 1;j < n;j++) {
                if(j > i + 1 && nums[j] == nums[j-1])     continue;
                int lhs = j + 1,rhs = n - 1;
                while(rhs > lhs){
                    if(rhs != n-1 && nums[rhs] == nums[rhs+1])   rhs--;
                    else if(lhs != j+1 && nums[lhs] == nums[lhs-1])      lhs++;
                    else if(nums[i] + nums[lhs] + nums[rhs] + nums[j] > target)   rhs--;
                    else if(nums[i] + nums[lhs] + nums[rhs] + nums[j] < target)   lhs++;
                    else{
                        res.push_back((vector<int>){nums[i],nums[j],nums[lhs],nums[rhs]});
                        lhs++;
                        rhs--;
                    }
                }
            }
        }
        return res;
    }
};