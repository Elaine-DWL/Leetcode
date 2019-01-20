#include <iostream>

using namespace std;
class Solution {
public:
    bool isPrime(int n){// 判断一个数是否为素数，时间复杂度是O(n)
        if(n<=1) return false;
        for(int i=2; i*i<=n; i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int countPrimes(int n) {
//        unordered_map<int, bool> mp;// true表示该数是质数
        bool mp[n]={0};
        int sum=0;
        mp[1]=false;
        for(int i=2; i<n; i++){
            if(isPrime(i)){
                 mp[i] = true;
                 sum++;
            }
            else mp[i] = false;
            // 标记所有它的倍数都不是质数
            // 标记方法1
            int t=i*2;
//            for(int j=2; t<n; j++){
//                t *= j;
//                mp[t]=false;
//            }
            // 标记方法2
            for(int j=i*i; j<n; ){
                mp[j] = false;
                j = j+i;
            }
        }
        return sum;
    }
};


class Solution{
public:
    int countPrimes(int n) {// 统计素数个数
        if(n==1||n==2) return 0;
        if(n==3) return 1;
        bool mp[n]={0};// 初始化都是素数
        for(int i=2; i<n; i++){// 判断i是不是素数
            if(mp[i]==1) continue;
            for(int k=i*i; k<n; k++) mp[k]=1;
            for(int j=2; j*j<=i; j++){
                if(i%j==0){// 这个数不是素数
                    mp[i] = 1;// 标记不是素数
                    continue;
                }
            }
        }
        int res=0;
        for(int i=3; i<n; i++){
            if(mp[i]==0) res++;
        }
        return res;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
class Solution{
public:
    int countPrimes(int n) {// 统计素数个数
        if(n<3) return 0;
        if(n==3) return 1;
        vector<bool> mp(n,0);
        // bool mp[n]={0};// 初始化都是素数
        int res=0;
        for(int i=2; i<n; i++){// 判断i是不是素数
            if(mp[i]==1) continue;// 如果已经被标记过不是素数，则跳过
            // 当前数未被标记过，所以需要重新判断是否为素数
            for(int k=i+i; k<n; k+=i) mp[k]=1;// 标记该数的所有倍数都不是素数
            res++;
        }
        return res;
    }
};
