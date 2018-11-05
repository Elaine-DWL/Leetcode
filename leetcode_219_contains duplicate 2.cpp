#include <iostream>
#include <vector>

using namespace std;

// 直接暴力  报错是超时
class Solution{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k){
        for(int i=0; i<nums.size(); i++){
            for(int j=1; j<=k; j++){
                if(i+j<nums.size() && nums[i]==nums[i+j]) return true;
            }
        }
        return false;

    }
};

// 用哈希表来做
class Solution{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k){
        unordered_map<int, int> myhash;
        for(int i=0; i<nums.size(); i++){
            if(myhash.count(nums[i])==0) myhash[nums[i]] = i;
            else if(myhash[nums[i]]-i<=k && myhash[nums[i]]-i>=-k) return true;
            else myhash[nums[i]] = i;
        }
        return false;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
