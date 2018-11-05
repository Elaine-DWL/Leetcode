#include <iostream>
#include <vector>
using namespace std;
// 方法1 insert和erase方法
class Solution{
public:
    void rotate(vector<int>& nums, int k){
        for(int i=0; i<k; i++){
            nums.insert(nums.begin(), *(nums.end()-1));
            nums.erase(nums.end()-1);
        }
    }
};
// 用reverse函数，注意这里的k很有可能大于数组的大小
class Solution{
public:
    void rotate(vector<int>& nums, int k){
        k = k%nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin()+k, nums.end());
        reverse(nums.begin(), nums.begin()+k);
    }
};
// 用空间换时间
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       if(k<1 || k%nums.size() == 0) return;
        vector<int> temp(nums.size());
        k = k%nums.size();
        for(int i=0; i<k; i++){
            temp[i] = nums[nums.size()-k+i];
        }
        for(int i=k; i<nums.size(); i++){
            temp[i] = nums[i-k];
        }
        nums = temp;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
