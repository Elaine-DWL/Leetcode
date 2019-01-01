class Solution {
public:
    int romanToInt(string s) {
        map<string, int> mp;
        vector<int> a({1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000});
        vector<string> b({"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"});
        int n=a.size()-1;
        for(int i=0; i<=n; i++){
            mp[b[i]] = a[i];
        }
        int res=0;
        for(int i=0; i<s.size(); ){
//             如果向后看一个还是在map中的话  那就
            string symbol(s, i, 2);
            if(i!= s.size()-1 && mp.count(symbol)!=0){
                res += mp[symbol];
                i=i+2;
            }
            else{
                symbol = s.substr(i, 1);
                res += mp[symbol];
                i++;
            }
                
        }
        return res;
    }
};