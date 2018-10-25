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
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
