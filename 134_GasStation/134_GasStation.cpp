 /**
 * 题目地址： https://leetcode-cn.com/problems/gas-station/description/
 * 解题思路： 1. 如果cost总和大于gas总和肯定不能走完
 *			  2. 当到达某一站点时，若当前值小于0了，则说明从起点到这个点中间的任何一个点都不能作为起点，则把起点设为下一个点
 */
 
 
// my version
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = -1; bool flag = true;
        for(int i = 0; i < gas.size(); i++){
            if(gas[i] < cost[i]) continue;
            else{
                int station = i; int temp = gas[i];
                for(int j = 0; j < gas.size(); j++){
                    if(temp - cost[station%gas.size()] < 0){
                        flag = false;
                        break;
                    }
                    temp = temp - cost[station%gas.size()] + gas[(station+1)%gas.size()];
                    station++;
                }
                if(flag)
                    return i;
                flag = true;
            }
        }
        return res;
    }
};

//good solution
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, sum = 0, start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (sum < 0) {
                start = i + 1;
                sum = 0;
            }
        }
        return (total < 0) ? -1 : start;
    }
};