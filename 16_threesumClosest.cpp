class Solution {
public:
    
    int min(int a, int b, int target){
        return abs(a-target) < abs(b-target)?a:b;
    }
    
    int threeSumClosest(vector<int>& num, int target) {
        sort(num.begin(),num.end());
        int n = num.size();
        int closest = num[0] + num[1] + num[n-1];
        for(int i = 0; i < n; i++){                             //枚举a
            if(i && num[i] == num[i-1])     continue;           //排除重复的解
            int lhs = i+1,rhs = n-1;                            //b和c的下标
            while(rhs > lhs){                                   //O(n)枚举b和c
                 closest = min((num[i] + num[lhs] + num[rhs]),closest, target);
                 if(rhs != n-1 && num[rhs] == num[rhs+1])   rhs--;              //排除重复的解
                 else if(lhs != i+1 && num[lhs] == num[lhs-1])      lhs++;      //排除重复的解
                 else if((num[i] + num[lhs] + num[rhs]) < target)   lhs++;             
                 else if((num[i] + num[lhs] + num[rhs]) > target)   rhs--;
                 else{
                     return target;
                 }
            }
        }
        return closest;
    }
};