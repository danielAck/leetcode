 /**
 * 题目地址： https://leetcode-cn.com/problems/insert-interval/description/
 * 解题思路： 1. 考虑重叠和不重叠两种情况，先将不重叠的部分直接加入res，再将重叠的部分进行不断的合并(第二个while循环)
 * 				 最后将合并好的区间加入res，再把剩余的区间加入res
 */

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int n = intervals.size(), cur = 0;
        while (cur < n && intervals[cur].end < newInterval.start) {
            res.push_back(intervals[cur++]);
        }
        while (cur < n && intervals[cur].start <= newInterval.end) {
            newInterval.start = min(newInterval.start, intervals[cur].start);
            newInterval.end = max(newInterval.end, intervals[cur].end);
            ++cur;
        }
        res.push_back(newInterval);
        while (cur < n) {
            res.push_back(intervals[cur++]);
        }
        return res;
    }
};