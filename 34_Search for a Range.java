class Solution {
    
    public int[] bisearch(int[] list,int l, int r, int target){
        //没有找到的情况
        if(l > r){
            return new int[]{-1,-1};
        }
        //出现分治后 target 是单个的情况
        if(l == r && list[l] == target) return new int[]{l,l};
        //出现分治后 target 连续的情况
        if(list[l] == list[r] && list[l] == target) return new int[]{l,r};
        
        int[] res= new int[]{-1,-1};
        int mid = (l+r)/2;
        if(list[mid] < target){
            res = bisearch(list, mid+1, r, target);
        }
        else if (list[mid] > target){
            res = bisearch(list, l, mid-1, target);
        }
        else{ // 
            int[] res1 = bisearch(list, l, mid, target);
            int[] res2 = bisearch(list, mid+1, r, target);
			// 合并下标, 下标有三种情况：[-1,-1], [2,2], [3,6]
            if(res1[0] == -1) return res2;
            else if(res2[0] == -1) return res1;
            else return new int[]{res1[0],res2[1]};
        }
        return res;
    }
    public int[] searchRange(int[] nums, int target) {
        return bisearch(nums, 0, nums.length-1, target);
    }
}