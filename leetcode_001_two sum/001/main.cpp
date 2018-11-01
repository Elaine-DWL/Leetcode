#include <iostream>

using namespace std;
// 这里是返回的数值 ， 但题目是要求返回下标
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int num:nums) mp[num]++;
        for(auto upair:mp){
            int t = upair.first;
            if(t==target-t && mp[upair.first]>=2;) return vector<int>({t,t});
            if(mp.count(target-t)!=0) return vector<int>({t,target-t});
        }
    }
};
class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, vector<int>> mp;
        int n=nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        for(int i=0; i<n; i++){
            int t = target-nums[i];
            if(t==nums[i] && mp[t].size()>1) return vector<int>({i, mp[t][1]});
            if(mp.find(t)!=0) return vector<int>(i, mp[t][0]);
        }
    }

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}



cmake  ../opencv-3.4.2 -DWITH_GTK_2_X=ON -DCMAKE_INSTALL_PREFIX=/usr/local -DCMAKE_BUILD_TYPE=RELEASE -DCMAKE_INSTALL_PREFIX=/usr/local -DWITH_TBB=ON -DBUILD_NEW_PYTHON_SUPPORT=ON -DWITH_V4L=ON -DINSTALL_C_EXAMPLES=ON -DINSTALL_PYTHON_EXAMPLES=ON -DBUILD_EXAMPLES=ON  -DWITH_OPENGL=ON -DENABLE_FAST_MATH=1 -DCUDA_FAST_MATH=1 -DWITH_CUBLAS=1 -DWITH_OPENMP=ON
---------------------
作者：dfgbddsv
来源：CSDN
原文：https://blog.csdn.net/u011128775/article/details/80790638
版权声明：本文为博主原创文章，转载请附上博文链接！
