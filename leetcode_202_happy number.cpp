#include <iostream>
#include <set>
#include <string>
using namespace std;
// 用set来做
class Solution {
public:
    int cal(int n){// 返回当前数 各个位置上数字的平方和
        int sum=0;
        while(n!=0){
            sum += (n%10)*(n%10);
            n = n/10;
        }
        return sum;

    }
    bool isHappy(int n) {
        set<int> myset;
        int t = cal(n);// 计算平方和
        while(t!=1){
            if(myset.count(t)==1) return false;
            myset.insert(t);
            t = cal(t);
            if(t==1) return true;
        }
    }
};
// Floyd算法判断是否有闭环

class Solution{
public:
    int cal(int n){
        string s=to_string(n);
        int sum=0;
        for(char num:s){
            sum += (num-'0')*(num-'0');
        }
       // cout<<"sum: "<<sum<<endl;
        return sum;
    }
    bool isHappy(int n){
        int slow=n, fast=n;
        while(slow!=1 && fast!=1){
            slow = cal(slow);// 走一步
            if(slow==1) return true;
            fast = cal(cal(fast));//走两步
            if(slow==fast) return false;
        };
        return true;
    }
};
int main()
{
    int n;
    cin >> n;
    int x[n];
    cout << "Hello world!" << endl;
    return 0;
}
