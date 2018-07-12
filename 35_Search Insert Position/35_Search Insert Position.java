class Solution { 
    
    int bisearch(int[] list, int l, int r, int target){
        if(l > r){
            if(r < 0) return r+1;
            else return l;
        }
        int center = (l+r)/2;
        if(list[center] > target) r = center-1;
        else if(list[center] < target) l = center + 1;
        else return center;
        return bisearch(list, l, r, target);
    }
    
    public int searchInsert(int[] nums, int target) {
        return bisearch(nums, 0, nums.length-1, target);
    }
}