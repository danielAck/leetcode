/*
 * 题目地址： https://leetcode-cn.com/problems/container-with-most-water/description/
 * 解题思路： 1.面积取决于两个因素： 长度和最短高度
 *          2.使用 定一个变量然后夹逼 的思想，不断的缩小长度，由于取决于最短高度，所以移动指向最短高度的指针，相当于在扩大最短大小
 *            因为长度已经在缩小，如果最短长度还在缩小那最大面积不变，而如果最短长度扩大，那么可以比较一下最大面积是否增大
 */

class Solution {
    public int maxArea(int[] height) {
        
        int i = 0; int j = height.length -1;
        int maxarea = -1;
        
        while(i < j){
            maxarea = Math.max(maxarea, Math.min(height[i],height[j]) * (j-i));
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        return maxarea;
    }
}