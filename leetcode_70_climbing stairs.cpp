// 动态规划 递归
class Solution {
public:
    int f(int n){
        if(n==1) return 1;
        if(n==2) return 2;
        return f(n-1)+f(n-2);
    }
    int climbStairs(int n) {
        return ;
    }
};
// 动态规划  直接算

class Solution {
public:
    // int f(int n){
    //     if(n==1) return 1;
    //     if(n==2) return 2;
    //     return f(n-1)+f(n-2);
    // }
    int climbStairs(int n) {
        int f[n];
        f[0] = 1;
        for(int i=1; i<n; i++){
            if(i==1) f[i]=1;
            else if(i==2) f[i]=2;
            else f[i] = f[i-1]+f[i-2];
        }
        if(n==1 || n==2) return n;
        
        return f[n-1]+f[n-2];
    }
};