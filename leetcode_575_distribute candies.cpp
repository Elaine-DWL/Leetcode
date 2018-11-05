class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_map<int, int> mp;
        for(int num:candies) mp[num]++;
        int n=candies.size()/2;
        int sum=0;
        unordered_map<int, int>::iterator ite=mp.begin();
        for(; ite != mp.end(); ite++){
            if(sum<n) sum++;
            if(sum==n) return n;
        }
        return sum;
    }
};