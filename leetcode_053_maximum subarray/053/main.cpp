#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    int maxSubArray(vector<int> &nums){
       int res = -65535;
       int cursum = nums[0];
       for(int i=1; i<nums.size(); i++){
            if(cursum > 0) cursum += nums[i];
            else cursum = nums[i];
            if(cursum > res) res = cursum;
       }
       return res;
    }
};
int main()
{
    int a[]={-2,1,-3,4,-1,2,1,-5,4};
    int b;
    //cin>>b;
    vector<int> num(a, a+8);
    Solution A;
    A.maxSubArray(num);
}
