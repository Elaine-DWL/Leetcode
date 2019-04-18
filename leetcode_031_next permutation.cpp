// 之前的做法
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || n==1) return;
        int first;
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                int j=i+1;
                while(j<=n-1 && nums[j]>nums[i]) j++;
                j--;
                swap(nums[i], nums[j]);
                sort(nums.begin()+i+1, nums.end());
                return;
                }
        }
        sort(nums.begin(), nums.end());
        return;
    }
};

// 三个月之后  20190418的做法
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 求下一个排列数
        // 要求空间复杂度是O(1)
        int p1=-1, p2=-1;
        // 从右到左找出第一个递减位置的数  用p1记录
        for(int i=nums.size()-1; i>0; i--){
            if(nums[i]>nums[i-1]){
                p1 = i-1;
                break;
            }
        }
        if(p1==-1){
            reverse(nums.begin(), nums.end());
            return;
        }
        // 从p1开始 找到第一个比p1处的数小
        p2 = nums.size()-1;
        for(int i=p1; i<nums.size()-1; i++){
            if(nums[i+1] <= nums[p1]){
                p2 = i;
                break;
            }
        }
        swap(nums[p1], nums[p2]);
        sort(nums.begin()+p1+1, nums.end());
    }
};