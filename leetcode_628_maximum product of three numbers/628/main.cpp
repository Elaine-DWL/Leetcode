#include <iostream>

using namespace std;
// 求最大的三个数的乘积
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int a[3]={0};//a[0]最大，a[1]次之，a[2]最小
        int b[2]={0};// 负数
        if(nums.size()==3) return nums[0]*nums[1]*nums[2];
        // 先找最大的三个正数
        for(int i=0; i<nums.size(); i++){
            int cur = nums[i];
            if(nums[i]<0){
                if(cur < b[1]){
                    if(cur <= b[0]){
                        b[1] = b[0];
                        b[0] = cur;
                    }
                    else b[1]=cur;
                }
                continue;
            }
            if(cur<=a[2]) continue;
            else{
                if(cur>=a[0]){
                    a[2] = a[1];
                    a[1] = a[0];
                    a[0] = cur;
                }
                else if(cur>=a[1]){
                    a[2] = a[1];
                    a[1] = cur;
                }
                else a[2] = cur;
            }
        }
        int a1=b[0]*b[1]*a[0], a2=a[0]*a[1]*a[2];
        return a1>a2?a1:a2;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
