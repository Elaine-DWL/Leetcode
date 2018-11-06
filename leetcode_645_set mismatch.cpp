class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int mp[10001]={0};
        int dup;
        int sum=0;
        for(int num:nums){
            if(mp[num]==1)  dup=num;
            mp[num]++;
            sum += num;
        }
        return vector<int>({dup, n*(n+1)/2 - sum +dup});
        
    }
};