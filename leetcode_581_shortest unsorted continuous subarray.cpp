#include <iostream>

using namespace std;


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> tmp;
        tmp.assign(nums.begin(), nums.end());
        int n=nums.size();
        int p1=0;
        int p2=n-1;
        sort(tmp.begin(), tmp.end());
        for(; p1<nums.size(); p1++){
            if(tmp[p1] != nums[p1]){
                break;
            }
        }
        if(p1==nums.size()-1) return 0;
        for(; p2>=p1; p2--){
            if(tmp[p2] != nums[p2]){
                break;
            }
        }
        return p2-p1+1;

    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
