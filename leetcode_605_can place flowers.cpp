#include <iostream>

using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt=0;
        vector<int> nums;
        vector<int> sum(2, 0);
        for(int num:flowerbed) sum[num]++;
        if(sum[1] == 0) return (sum[0]+1)/2 >= n;

        for(int i=0; i<flowerbed.size(); i++){
            if(flowerbed[i]==0){
                cnt++;
            }
            else{
                if(cnt==0) nums.push_back(-1);
                else{
                    nums.push_back(cnt);
                    nums.push_back(-1);
                    cnt=0;
                }
            }
            if(cnt!=0 && i==flowerbed.size()-1) nums.push_back(cnt);
        }
        cnt=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=-1){
               // if(i==nums.size()-1) cnt += (nums[i]+1)/2;
                if(i==0 || i==nums.size()-1) cnt += nums[i]/2;
                else cnt += (nums[i]-1)/2;
            }
        }
        return n<=cnt;
};

// 更简便的方法二
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        for(int i=1; i<flowerbed.size()-1; i++){
            if(n==0) return true;
            if(flowerbed[i] + flowerbed[i-1] +flowerbed[i+1] == 0){
                n--;
                flowerbed[i] = 1;
            }
        }
       return n==0;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
