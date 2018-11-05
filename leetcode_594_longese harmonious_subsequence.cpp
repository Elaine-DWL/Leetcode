class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> mp;
        for(int num:nums) mp[num]++;
        int max_length = 0;
        map<int, int>::iterator ite = mp.begin();
        int pre=LONG_MAX, pre_num=0;
        for(; ite!=mp.end(); ite++){
            if(abs((*ite).first-pre) == 1){
                max_length = max((*ite).second + pre_num, max_length);
            }
            pre = (*ite).first;
            pre_num = (*ite).second;
        }
        return max_length;
    }
};