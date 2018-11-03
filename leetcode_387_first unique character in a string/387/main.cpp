#include <iostream>

using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        int mp[256]={0};
        for(auto ch:s) mp[ch]++;
        for(int i=0; i<s.size(); i++){
            if(mp[s[i]]==1) return i;
        }
        return -1;
    }
};
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, pair<int, int>> mp;
        for(int i=0; i<s.size(); i++){
            if(mp.count(s[i])==0){
                mp[s[i]].first=1; // 出现次数
                mp[s[i]].second=i;// 第一次出现的位置
            }
            else{
                mp[s[i]].first++;
            }
        }
        int ind=0x7fffffff;
        for(auto m:mp){
            if(m.second.first==1) ind = min(ind, m.second.second);
        }
        return ind==0x7fffffff?-1:ind;

    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
