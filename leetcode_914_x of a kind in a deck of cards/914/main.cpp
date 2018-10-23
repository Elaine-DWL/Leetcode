#include <iostream>

using namespace std;



class Solution {
public:
    int gcd(int x, int y){// 辗转相除法求最大公约数
        if(x*y==0) return x+y;
        if(x==y) return x;
        while(y!=0 && x%y!=0){
            int t =x;
            x = y;
            y = t%y;
        }
        return y;
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mp;
        int index;
        for(int num:deck){
            mp[num]++;
        }
        int t=0;
        for(auto num:mp){
                t = gcd(num.second, t);
        }
        return t!=1;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
