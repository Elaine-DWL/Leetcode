#include <iostream>

using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> res;
        for(int num:nums1) mp[num]++;
        for(int num:nums2){
            if(mp.count(num)==1 && mp[num]>0){
                res.push_back(num);
                mp[num] = -1;
            } 
        }
        return res;
    }
};
// 方法2
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s(nums1.begin(), nums1.end());
        vector<int> res;
        for(int num:nums2){
            if(s.erase(num))
                res.push_back(num);
        }
        return res;
    }
};
// 方法3 用set_intersection()
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end()), res;
        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(res, res.begin()));
        return vector<int>(res.begin(), res.end());
    }
};