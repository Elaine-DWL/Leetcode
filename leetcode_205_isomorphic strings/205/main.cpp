#include <iostream>

using namespace std;
// ·¨Ò»
// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         unordered_map<char, int> mp;
//         vector<int> s1, t1;
//         int ind=0;
//         mp[s[0]] = ind;
//         s1.push_back(ind);
//         for(int i=1; i<s.size(); i++){
//             if(mp.count(s[i])==0){
//                 ind++;
//                 mp[s[i]] = ind;
//             }
//             s1.push_back(mp[s[i]]);
//         }
//         mp.clear();
//         ind = 0;
//         mp[t[0]] = ind;
//         t1.push_back(ind);
//         for(int i=1; i<t.size(); i++){
//             if(mp.count(t[i])==0){
//                 ind++;
//                 mp[t[i]] = ind;
//             }
//             t1.push_back(mp[t[i]]);
//             if(t1[i]!=s1[i]) return false;

//         }
//         return true;
//     }
// };
// ·¨2
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
