// 思路一  直接调用next_permutation()
class Solution {
public:
    string getPermutation(int n, int k) {
        string res="";
        for(int i=0; i<n; i++){
            res = res + to_string(i+1); 
        }
        for(int i=0; i<k-1; i++){
            next_permutation(begin(res), end(res));
        }
        return res;
        
    }
};

// 思路2 找规律的方法
class Solution {
public:
    // int jie(int n){ // calculate n!
    //     int res=1;
    //     for(int i=1; i<=n; i++){
    //         res *= i;
    //     }
    //     return res;
    // }
    string getPermutation(int n, int k) {
        int jie[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);
        string res="";
        k = k-1;
        int t;
        for(int i=0; i<n; i++){
            t = k / jie[n-i-1];
            res += to_string(nums[t]);
            nums.erase(nums.begin()+t);
            k = max(k-t*jie[n-i-1], 0);
        }
        return res;
    }
};

