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