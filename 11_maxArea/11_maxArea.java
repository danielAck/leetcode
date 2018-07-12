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