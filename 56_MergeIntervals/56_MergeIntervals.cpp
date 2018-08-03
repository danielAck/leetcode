 /**
 * 题目地址： https://leetcode-cn.com/problems/insert-interval/description/
 * 解题思路： 解法一： 可以借用57题的思路，相当于对列表中的每一个区间执行插入方法，最终获得最后的结果
 *			  解法二： 1. 使用自定义的sort函数对区间进行排序(按begin排序)
 * 					   2. 从第二个区间开始遍历，如果没有重叠直接加入res，如果有重叠不断的修改当前区间的范围(即进行合并),直到和后面的区间没有重叠为止
 * 					   3. 将当前区间加入res，重复之前的步骤
 */

// 解法一
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
    
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.size()==0) return res;
        for(int i = 0; i < intervals.size(); ++i){
            res = insert(res, intervals[i]);
        }
        
        return res;
    }
};

//解法二

class Solution {
public:
	// 自定义sort函数排序规则
    static bool cmp(Interval &a, Interval &b){
        return a.start < b.start;
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> res{intervals[0]};
        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back().end < intervals[i].start) {
                res.push_back(intervals[i]);
            } else {
                res.back().end = max(res.back().end, intervals[i].end);
            }
        }   
        return res;
    }
};