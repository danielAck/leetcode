/*
 * 题目地址： https://leetcode-cn.com/problems/subsets/description/
 * 解题思路： 1. 根是空集，左子树代表添加以当前层数为下标的元素，右子树代表不添加，所有的结果在根节点上
 *            
 */
 
class Solution {
public:
    
    void fun (vector<int>& nums,vector<vector<int>>& res, vector<int> temp, int level){
        if(level == nums.size()){
            res.push_back(temp);
            return;
        }
        fun(nums, res, temp, level+1); // 不加数字
        temp.push_back(nums[level]);
        fun(nums, res, temp, level+1); // 加数字
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        fun(nums, res, temp, 0);
        return res;
    }
};