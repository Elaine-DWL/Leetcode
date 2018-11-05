#include <iostream>

using namespace std;
class Solution{
public:
    int findPairs(vector<int>& nums, int k){
        int n=nums.size();
        if(n/2 == 0) return 0;
        sort(nums.begin(), nums.end());
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i]-nums[j]==k || nums[i]-nums[j]==-k) cnt++;
                else break;
            }
        }
        returnu cnt;
    }
};
// ¹şÏ£·½·¨
class Solution{
public:
    int findPairs(vector<int>& nums, int k){
        if(nums.size()/2==0 || k<0) return 0;
        unordered_map<int, int> myhash;
        int cnt=0;
        for(int num:nums) myhash[num]++;
        for(auto p:myhash){
            if(k==0){
                if(p.second >= 2) cnt++;
            }
            else{
                if(myhash.find(p.first + k) != myhash.end()) cnt++;
            }
        }
        return cnt;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
