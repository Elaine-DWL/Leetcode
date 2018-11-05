#include <iostream>

using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return -1;
        if(n==1) return 0;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        for(int i=n-1; i>=0; i--){
            if(i==n-1) right[i] = 0;
            else right[i] = right[i+1] + nums[i+1];
        }

        for(int i=0; i<n; i++){
            if(i==0) left[i] = 0;
            else
            left[i] =left[i-1] + nums[i-1];
            if(left[i]==right[i]) return i;
        }

        return -1;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
