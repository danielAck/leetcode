class Solution {
public:

// 使用DFS遍历
vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > res;
        vector<int> tmp;
        dfs(0,0,candidates,tmp,res,target);
        return res;
    }
    
    // 递归返回空值，通过参数带回多个值
    void dfs(int cur,int depth,vector<int> &candidates,vector<int> tmp,vector<vector<int> > &res,int target)
    {
        if(target == 0){
            res.push_back(tmp);return ;
        }
        for(int i = cur;i < candidates.size();i++){
            //两个剪枝，当前数大于目标值或当前数在该层已经被搜过要跳过
            if(target - candidates[i] < 0)   break;
            if(i != cur && candidates[i] == candidates[i-1])  continue;
            if(tmp.size() == depth)     tmp.push_back(candidates[i]);
            else    tmp[depth] = candidates[i];
            dfs(i,depth + 1,candidates,tmp,res,target - candidates[i]);
        }
    }
};