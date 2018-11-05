#include <iostream>

using namespace std;
// 136ms 30.51%
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>::iterator new_end = unique(nums.begin(), nums.end());
        // 无重复元素个数
        int m =new_end - nums.begin();
        vector<int> res();
        for(int i=0,j=0; j<n; j++){// 总共有m个
            if(i==m || nums[i]!=nums[j]){
                res.push_back(j+1);
                continue;
            }
            i++;
        }
    }
};
// 解法2 144ms 28.94%
class Solution{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums){
        int a[nums.size()]={0};
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            if(++a[nums[i]-1] > 1) sum++;
        }
        vector<int> res;
        for(int i=0; i<nums.size()&&sum>0; i++){
            if(a[i]==0){
              res.push_back(i+1);
              sum--;
            }
        }
        return res;
    }
};
// 解法三
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for(int i=0; i<len; i++) {
            int m = abs(nums[i])-1; // index start from 0
            nums[m] = nums[m]>0 ? -nums[m] : nums[m];
        }
        vector<int> res;
        for(int i = 0; i<len; i++) {
            if(nums[i] > 0) res.push_back(i+1);
        }
        return res;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
