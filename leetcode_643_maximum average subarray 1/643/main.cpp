#include <iostream>
#include <float.h>
#include<limits.h>
using namespace std;
// ±©Á¦½â·¨
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double aver= -9999999;
        for(int i=k-1; i<nums.size(); i++){
            int t=0;
            for(int j=i-k+1; j<=i; j++){
                t += nums[j];
            }
            aver = t>aver?t:aver;
        }
        return aver/k;
    }
};
//
class Solution{
    double findMaxAverage(vector<int>& nums, int k){
        double aver = -9999999;
        double cur = 0;
        for(int i=0; i<k; i++){
            cur += nums[i];
        }
        aver = max(aver, cur);
        for(int i=k; i<nums.size(); i++){
            cur = cur-nums[i-k]+nums[i];
            aver = max(aver, cur);
        }
        return aver;
    }
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
