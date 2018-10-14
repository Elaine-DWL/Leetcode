#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int allsum = (n+1)*n/2;
        int asum = 0;
        for(int i=0; i<nums.size(); i++){
            asum += nums[i];
        }
        return allsum - asum;
    }
};
// 位操作的方法
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total ^= nums[i];
        }

        for (int i = 0; i <= nums.size(); i++) {
            total ^= i;
        }

        return total;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
