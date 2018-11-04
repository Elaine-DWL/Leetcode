#include <iostream>

using namespace std;
// 方法1
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> mp(256, 0), tmp(256,0);
        vector<int> res;
        for(char ch:p) mp[ch]++;
        int sn=s.size(), pn=p.size();
        for(int i=0; i<=sn-pn; i++){
            tmp = mp;
            bool flag=false;
            for(int j=i; j<i+pn; j++){
                tmp[s[j]]--;
                if(tmp[s[j]]<0){
                    flag=true;
                    break;
                }
            }
            if(!flag) res.push_back(i);
        }
        return res;
    }
};


// 方法2
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size()) return vector<int>();
        vector<int> smp(128, 0), pmp(128,0);
        vector<int> res;
        cout<<s.size()<<endl;
        for(char ch:p) pmp[ch]++;
        int n = p.size();
        for(int i=0; i<n; i++){
            smp[s[i]]++;
        }
        for(int i=0; i<s.size()-n+1; i++){
            if(smp==pmp) res.push_back(i);
            if(i!=s.size()-n){
                smp[s[i]]--;
                smp[s[i+n]]++;
            }
        }
        return res;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
