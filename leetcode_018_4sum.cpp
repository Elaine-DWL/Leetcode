// 找出四元组 使得它们的和为target
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n=nums.size();
        if(n <= 3) return res;
        sort(nums.begin(), nums.end());
        for(int four=0; four<n-3;){
            for (int three=four+1; three<n-2;){
                int head=three+1, tail=n-1, aim=target-nums[three]-nums[four];
                while(head < tail){
                    if(nums[head]+nums[tail] == aim){
                       res.push_back(vector<int>({nums[four], nums[three], nums[head], nums[tail]})); 
                        head++;
                        tail--;
                        while(nums[head]==nums[head-1] && head+1<=tail) head++; // 注意1  这里的<=  是为了防止[3 3 3 3]  如果第1/4个3满足情况(head=第一个3， tail=第4个3)，那么使用<号的话 会把第2/3个3也算作一种情况
                        while(nums[tail]==nums[tail+1] && tail-1>=head) tail--; // 注意2
                    }
                    else if(nums[head]+nums[tail] < aim) head++;
                    else tail--;
                }
                three++;
                while(nums[three]==nums[three-1] && three+1<n) three++; // 注意3  这里是<n   而不是<n-2
            }
            four++;
            while(nums[four]==nums[four-1] && four+1<n) four++; // 注意4 这里是<n  而不是<n-2
            
        }
        return res;
    }
};