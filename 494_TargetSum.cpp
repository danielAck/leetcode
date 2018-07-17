/*
 * 题目地址： https://leetcode-cn.com/problems/target-sum/description/
 * 解题思路： 1.DFS遍历所有情况
 *          2.动态规划方程： ways[i][j] = ways[i - 1][j - nums[i]] + ways[i - 1][j + nums[i]]
 *             ways[i][j] - 代表数组中第i个元素之前和为j的情况个数
 *          讲解视频： https://www.youtube.com/watch?v=r6Wz4W1TbuI
 */

// 递归解法，368ms，30%
class Solution {
public:
    // 返回可能的种数
    int fun(vector<int>& nums, int target, int level){
        if(level == nums.size()){
            if(target == 0)
                return 1;
            else
                return 0;
        }
        else
            return fun(nums, target - nums[level], level+1) + fun(nums, target + nums[level], level+1);
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        return fun(nums, S, 0);
    }
};

// 标准的 dp 方法的代码
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S){
        const int n = nums.size();
        // accumulate对vector中的元素求和
        const int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum < S) return 0;

        // 设置偏移量指向 0， 左边是负值，右边是正值
        const int offset = sum;

        // 初始化数组大小为 两倍的 sum + 1
        vector<vector<int>> ways(n+1, vector<int>(2 * sum + 1, 0));
        ways[0][offset] = 1;
        for (int i = 0; i < n; ++i)
        {
            for (int j = nums[i]; j < 2 * sum + 1; ++j)
            {
                if (ways[i][j]) //当dp数组中的值不是0
                {
                    ways[i + 1][j + nums[i]] += ways[i][j];
                    ways[i + 1][j - nums[i]] += ways[i][j];
                }
            }
        }

        return ways.back()[offset + S];
    }
}