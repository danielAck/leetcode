 /**
 * 题目地址： https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/description/
 * 解题思路： 1. 价格一升就可以买，一降就可以卖
 */

// my solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0; int cur = -1; int day = 0; int total = prices.size();
        bool wait = true;
        if(total < 2) return profit;
        while(day < total-1){
            if(wait){
                if(prices[day+1] > prices[day]){
                    //买入
                    cur = prices[day];
                    wait = false;
                }
            }else{
                if(prices[day+1] < prices[day]){
                    //卖出
                    profit += (prices[day]-cur);
                    wait = true;
                }
            }
            day++;
        }
        //最后一天还在持有
        if(!wait)
            profit += (prices[day]-cur);
        return profit;
    }
};

// good solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, n = prices.size();
        for (int i = 0; i < n - 1; ++i) {
            if (prices[i] < prices[i + 1]) {
                res += prices[i + 1] - prices[i];
            }
        }
        return res;
    }
};