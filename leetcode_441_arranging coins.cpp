// 暴力
class Solution {
public:
    int arrangeCoins(int n) {
        if(n<=1) return n;
        int step = 1;// 先把第一层放慢
        int res=n-step;
        step++;
        while(res>=step){
            res = res-step;
            step++;
        }
        return step-1;
    }
};

// 二分法
class Solution {
public:
    int arrangeCoins(int n) {
        long long left=1, right=n;
        while(left <= right){
            long long mid = left+(right-left)/2;
            long long t = mid*(mid+1)/2;
            if(t<n) left = mid+1;
            else if(t==n) return mid;
            else right = mid-1;
        }
        return right;
    }
};