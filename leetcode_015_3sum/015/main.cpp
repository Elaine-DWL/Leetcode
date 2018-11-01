#include <iostream>

using namespace std;
// 先暴力一下
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res(0, vector<int>(3));
        int n=nums.size();
        if(n<3) return res;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    if(nums[i]+nums[j]+nums[k]==0)
                    res.push_back(vector<int>({nums[i], nums[j], nums[k]}));
                }
            }
        }
        return res;
    }
};
//
class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        int n=nums.size;
        vector<vector<int>> res(0, vector<int>(3));
        map<int, int> mp;
        for(int num:nums){
            mp[num]++;
        }
        map<int, int>::iterator ite= mp.begin();
        for(; ite<mp.end(); ite++){
            if((*ite).second==1){
                for()
            }
        }

    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
