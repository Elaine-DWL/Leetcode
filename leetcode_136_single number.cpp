#include <iostream>

using namespace std;
// 哈希表实现
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int num:nums) mp[num]++;
        for(auto num:mp){
            if(num.second == 1) return num.first;
        }
    }
};
// 位操作来实现
class Solution{
public:
    int singleNumber(vector<int>& nums){
        int flag=0;
        for(int num:nums) flag ^= num;
        return flag;

    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
