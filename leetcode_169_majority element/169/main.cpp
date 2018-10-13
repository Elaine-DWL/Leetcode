// 这道题是要求数组中的众数，且其数量 > n/2
#include <iostream>
#include <map>
#include <vector>
using namespace std;
// 法1 遍历 借助hash  66.3% 16ms
class Solution{
public:
    int majorityElement(vector<int>& nums){
        map<int, int> myhash;
        int maj = nums[0];
        int num_maj=1;
        for(int i=0; i<nums.size(); i++){
            if(myhash.count(nums[i])==0) myhash[nums[i]] = 1;
            else myhash[nums[i]]++;
            if(myhash[nums[i]] > num_maj){
                num_maj = myhash[nums[i]];
                maj = nums[i];
            }
        }
        return maj;
    }
};

//-----------讨论区参考
//解法总结: https://leetcode.com/problems/majority-element/discuss/51612/6-Suggested-Solutions-in-C++-with-Explanations
public class Solution {
    public int majorityElement(int[] num) {

        int major=num[0], count = 1;
        for(int i=1; i<num.length;i++){
            if(count==0){
                count++;
                major=num[i];
            }else if(major==num[i]){
                count++;
            }else count--;

        }
        return major;
    }
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
