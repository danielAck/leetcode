// 解法一
// 直接快速排序，O(nlogn)
class Solution {
public:
    
    //一趟排序
    int partition(vector<int>& nums, int low, int high){
        int tem = nums[low]; //将第一个元素作为枢轴，进行存储
        while(low < high){
            while(low < high && nums[high] >= tem) high--;
            nums[low] = nums[high];
            while(low < high && nums[low] <= tem)  low++;
            nums[high] = nums[low];    
        }
        nums[low] = tem;
        return low; //返回枢轴位置
    }
    
    void qs(vector<int>& nums, int low, int high){
        if(low <= (high - 1)){     //长度大于1
            int mid = partition(nums, low, high);
            qs(nums, low, mid -1);  //排左边
            qs(nums, mid + 1, high);    //排右边
        }
    }
    void sortColors(vector<int>& nums) {
        qs(nums, 0, nums.size() - 1);
    }
};

// 解法二 O(n)
// 投机的方法：直接数 0，1, 2的个数，然后再一次顺序填好数组
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int cnt0 = 0,cnt1 = 0,cnt2 = 0;
        for(int i = 0;i < n;i++){
            if(nums[i] == 0)    cnt0++;
            else if(nums[i] == 1)   cnt1++;
            else    cnt2++;
        }
        for(int i = 0;i < n;i++){
            if(cnt0){
                nums[i] = 0;cnt0--;
            }
            else if(cnt1){
                nums[i] = 1;cnt1--;
            }
            else{
                nums[i] = 2;cnt2--;
            }
        }
    }
};


//解法三 O(n)
//利用了夹逼的思想
class Solution {
public:
    void sortColors(vector<int>& nums) {
		//设置指向等待填充颜色的区域的指针，red之前代表已经填好了red颜色，blue之后代表已经填好了蓝色
		int waite_paint_red=0, waite_paint_blue=nums.size()-1; 	
        for(int i=0; i<waite_paint_blue+1;)
        {
            if(nums[i]==0)
                swap(nums[i++], nums[waite_paint_red++]); //交换即填色的过程
            else if(nums[i]==2)
                swap(nums[i], nums[waite_paint_blue--]);
            else		//红色和蓝色两头填好，中间的白色自然就填好了
                i++;
        }
    }
};

