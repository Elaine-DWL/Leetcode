#include <iostream>

using namespace std;
class Solution {
public:
    bool isPrime(int n){// �ж�һ�����Ƿ�Ϊ������ʱ�临�Ӷ���O(n)
        if(n<=1) return false;
        for(int i=2; i*i<=n; i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int countPrimes(int n) {
//        unordered_map<int, bool> mp;// true��ʾ����������
        bool mp[n]={0};
        int sum=0;
        mp[1]=false;
        for(int i=2; i<n; i++){
            if(isPrime(i)){
                 mp[i] = true;
                 sum++;
            }
            else mp[i] = false;
            // ����������ı�������������
            // ��Ƿ���1
            int t=i*2;
//            for(int j=2; t<n; j++){
//                t *= j;
//                mp[t]=false;
//            }
            // ��Ƿ���2
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
