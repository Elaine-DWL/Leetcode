#include <iostream>

using namespace std;
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        //int a=max(nums[0], nums[1]), b=min(nums[0], nums[1]);
        int a=-1, b=-1;
        int index = 0;// 最大值的下标
        for(int i=0; i<n; i++){
            if(b >= nums[i]) continue;
            nums[i]>a ? b=a,a=nums[i],index=i:b=nums[i];
        }
        if(a >= 2*b) return index;
        return -1;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
