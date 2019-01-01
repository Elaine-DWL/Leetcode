// sort unique
class Solution {
public:
   bool cmp(int a, int b){
        return a>b;
    }
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        // unique(nums.begin(), nums.end());
        for(int x:nums) cout<<x<<" ";
        cout<<endl;
        return nums[k-1];
    }
};