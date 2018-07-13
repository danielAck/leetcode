/*
 * 题目地址： https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 * 解题思路： 1. 采用分治的思想，由于数组已经是有序的，直接用中位找不大于target的值快一些，但如果中位是target左右分治获得连续的下标，最后合并左右的下标返回就OK
 */

class Solution {
    
    public int[] bisearch(int[] list,int l, int r, int target){
        //没有找到的情况
        if(l > r){
            return new int[]{-1,-1};
        }
        //出现单个的情况
        if(l == r && list[l] == target) return new int[]{l,l};
        //出现全是连续的情况
        if(list[l] == list[r] && list[l] == target) return new int[]{l,r};
        
        int[] res= new int[]{-1,-1};
        int mid = (l+r)/2;
        if(list[mid] < target){
            res = bisearch(list, mid+1, r, target);
        }
        else if (list[mid] > target){
            res = bisearch(list, l, mid-1, target);
        }
        else{   // [-1,-1] - 没找到, [2,2] - 只有一个, [3,6] - 有多个, 下标有三种情况, 合并下标
            int[] res1 = bisearch(list, l, mid, target); // 得到左边的情况
            int[] res2 = bisearch(list, mid+1, r, target); // 得到右边的情况
            if(res1[0] == -1) return res2;                 // 左边没有
            else if(res2[0] == -1) return res1;            // 右边没有
            else return new int[]{res1[0],res2[1]};        // 合并
        }
        return res;
    }

    public int[] searchRange(int[] nums, int target) {
        return bisearch(nums, 0, nums.length-1, target);
    }
}