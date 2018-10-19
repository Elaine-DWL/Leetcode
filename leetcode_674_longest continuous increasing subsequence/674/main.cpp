#include <iostream>

using namespace std;
// Ì°ÐÄ½â·¨¡£
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
       int n = nums.size();
       if(n/2 == 0) return n;
       int max_len=1, cur_len=1;
       for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1]){
                cur_len++;
                max_len = max(max_len, cur_len);
            }
            else{
                cur_len = 1;
                max_len = max(max_len, cur_len);
            }
       }
       return max_len;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
