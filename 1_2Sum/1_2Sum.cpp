/*
 * 题目地址： https://leetcode-cn.com/problems/two-sum/description/
 * 解题思路： 1.暴力两层循环遍历所有情况
 *          2.使用 HashMap 线性查找 target - i 元素是否存在
 */

// Solution 1 (C++)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v(2);
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    v[0] = i;
                    v[1] = j;
                    return v;
                }
            }
        }
    }
};

// Solution 2 (Java)
class Solution {
    public int[] twoSum(int[] nums, int target) {
       HashMap <Integer,Integer> map=newHashMap<>(nums.length);
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            int another = target-num;
            Integer anotherIndex=  map.get(another);
            if (anotherIndex!=null) {
                return new int[] {  anotherIndex, i };
            }
            map.put(num,i);
        }
    }
}