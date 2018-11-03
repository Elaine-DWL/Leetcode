#include <iostream>

using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for(int num:nums1) mp[num]++;
        vector<int> res;
        for(int num:nums2){
            if(mp[num] > 0){
                res.push_back(num);
                mp[num]--;
            }
        }
        return res;
    }
};
vector<int> intersect(vector<int>& a, vector<int>& b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    a.erase(set_intersection(a.begin(), a.end(), b.begin(), b.end(), a.begin()), a.end());
    return a;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
