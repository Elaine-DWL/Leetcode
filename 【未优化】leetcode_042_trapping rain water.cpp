class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=2) return 0;
        vector<int> dp(height.size(), 0);
        // 首先从左往右遍历，记录dp[i] 也就是i左边的最高高度
        int cur_high = 0;
        for(int i=0; i<height.size(); i++){
            dp[i] = cur_high;
            cur_high = max(height[i], cur_high);
        }
        vector<int> dp2(height.size(), 0);
        cur_high = 0;
        for(int i=height.size()-1; i>=0; i--){
            dp2[i] = cur_high;
            cur_high = max(height[i], cur_high);
        }
        int res = 0;
        for(int i=0; i<height.size(); i++){
            if(height[i] < min(dp[i], dp2[i])) res += min(dp[i], dp2[i])-height[i];
        }
        return res;
    }
};