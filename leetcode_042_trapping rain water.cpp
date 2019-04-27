// 某个位置的积水  和它左边柱子的最高高度left、右边最该高度right 以及当前位置的高度有关cur
// 该位置积水高度 = min(left, right)>cur? min(left, right)-cur:0
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=2) return 0;
        vector<int> dp(height.size(), 0);
        // 首先从左网络遍历，记录dp[i] 记录左边的最高
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