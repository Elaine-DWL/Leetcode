//题目大意是，输出一个有序序列的无重复元素的个数 空间复杂度必须是o(1)
//注意到这里对空间复杂度有要求。而且题目的意思是，将无重复序列直接按顺序放在这个数组的前列
//所以我对本题的思路是，在原数组上设置两个游标，一个用于按顺序存储无重复序列，一个按顺序遍历原数组
//时间复杂度是o(n)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int len=1, i=0;
        vector<int>::iterator ite = nums.begin()+1;
        for(;ite<nums.end();ite++){
            if(nums[i]!=*ite){
                len++;
                nums[i+1] = *ite;
                i++;
            }
       }
       return len;
    }
};
int main()
{
    vector<int> nums;
    int t;
    while(scanf("%d", &t)!=EOF){
        nums.push_back(t);
    }
    Solution A;
    printf("%d",A.removeDuplicates(nums));
}
