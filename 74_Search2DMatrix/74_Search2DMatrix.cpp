
//解法一，由于有序，直接合并成一个数组，然后进行二分查找， 12ms - 74%
class Solution {
public:
    
    bool find(vector<int>& nums,int low, int high, int target){
        int mid = (high+low)/2;
        bool res = false;
        if(low > high) return false;
        else if(nums[mid] == target) return true;
        else if(nums[mid] > target) return find(nums, low, mid-1, target);
        else return find(nums, mid+1, high, target);
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> res;
        for(int i = 0; i < matrix.size(); i++){
            res.insert(res.end(), matrix[i].begin(), matrix[i].end());
        }
        return find(res, 0, res.size()-1, target);
    }
};

//解法二，二分再二分，还是12ms
class Solution {
public:
    
	//二分查找
    bool find(vector<int>& nums,int low, int high, int target){
        int mid = (high+low)/2;
        bool res = false;
        if(low > high) return false;
        else if(nums[mid] == target) return true;
        else if(nums[mid] > target) return find(nums, low, mid-1, target);
        else return find(nums, mid+1, high, target);
    }
    
	//第一个二分
    bool find2(vector<vector<int>>nums,int low, int high, int target){
        int mid = (low+high)/2;
        if(low > high || nums.size() == 0 || nums[mid].size() == 0) return false;
        if(target > nums[mid][nums[mid].size()-1])
            return find2(nums, mid+1, high, target);
        else if(target < nums[mid][0])
            return find2(nums, low, mid-1, target);
		//找到数字应在的数组，二分查找
        else return find(nums[mid], 0, nums[mid].size()-1, target);
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return find2(matrix, 0, matrix.size()-1, target);
    }
};