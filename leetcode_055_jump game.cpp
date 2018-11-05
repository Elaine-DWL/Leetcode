#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//-------思路（1）暴力求解，虽然AC，但是时间复杂度是o(n*n)，很容易超时
//class Solution {
//public:
//    bool canJump(vector<int>& nums) {
//        vector<int> can(nums.size()+1);
//        can[0] = 1;// can[i]=1表示能到达位置i
//        for(int i=0; i<nums.size(); i++){
//            if(can[i]==1){//能到达位置i，则从i开始试探着跳跃，来更新can[]
//                int step = nums[i];
//                for(int j=1; j<=step; j++){
//                    if(i+j < nums.size())   can[i+j]=1;
//                }
//            }
//
//        }
//        if(can[nums.size()-1]==1) return true;
//        return false;
//    }
//};

//-------思路（2）o(n)遍历数组 cover表示当前走到的最远的位置  最后cover>=nums.size()-1 说明能到达最后一个位置
//class Solution {
//public:
//    bool canJump(vector<int>& nums) {
//        int cover = 0;
//        for(int i=0; i<nums.size(); i++){
//            if(cover >= i)  cover = cover<i+nums[i]?i+nums[i]:cover;
//            else break;
//        }
//        if(cover >= nums.size()-1) return true;
//        return false;
//    }
//};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
