// 思路一 暴力
class NumArray {
public:
    vector<int> nums;
    NumArray(vector<int> nums) {
        this->nums = nums;
    }
    
    int sumRange(int i, int j) {
        if(i<0 || j>nums.size()-1) return 0;
        int sum=0;
        for(int k=i; k<=j; k++){
            sum += nums[k];
        }
        return sum;
    }
};

// 思路二 哈希 动态规划

class NumArray {
public:
    // vector<int> nums;
    vector<int> f;
    NumArray(vector<int> nums) {
        // this->nums = nums;
        f = vector<int>(nums.size());
        if(nums.size()!=0){
            f[0]=nums[0];
            for(int i=0; i<nums.size(); i++){
                f[i] = nums[i]+f[i-1];
            }
        }
    }
    
    int sumRange(int i, int j) {

       // if(i<0 || j>nums.size()-1) return NULL;
        int sum=0;
        return f[j] - f[i-1];
    }
};