/*
* Reference to https://github.com/gzwl/leetcode/blob/master/3Sum/3Sum.cpp?utm_source=qq&utm_medium=social&utm_oi=745026028811878400
*
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        sort(num.begin(),num.end());
        vector<vector<int> > res;
        int n = num.size();
        if(n < 3)   return res;
        for(int i = 0; i < n; i++){                             //枚举a
            if(i && num[i] == num[i-1])     continue;           //排除重复的解
            int lhs = i+1,rhs = n-1;                            //b和c的下标
            while(rhs > lhs){                                   //O(n)枚举b和c
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