// 找出和最接近target的數
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int distance=INT_MAX, res=nums[0];
        int n=nums.size();
        if(n==3) return nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            int head=i+1, tail=n-1;
            while(head < tail){
                int sum = nums[i] + nums[head] + nums[tail];
                if(sum == target) return target; 
                else if(sum < target)             
                    head++;
                else
                    tail--;
				
                if(abs(sum-target) < distance){
                        distance = abs(sum-target);
                        res = sum;
                }  
            }
        }
        return res;
    }
};