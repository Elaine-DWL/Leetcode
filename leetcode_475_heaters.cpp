// 思路一
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int n = heaters.size();
        int res = 0;
        for(int i=0; i<houses.size(); i++){// 遍历每个house
            int j=0;
            while(j<n-1 && abs(heaters[j]-houses[i])>=abs(heaters[j+1]-houses[i])) j++;
            res = max(res, abs(heaters[j]-houses[i]));
        }
        return res;
    }
};