// 求字符串的最长公共前缀
class Solution {
public:
    string twoCommon(string s1, string s2){
        // 找出字符串s1和s2的最长公共前缀   
        if(s2.size() < s1.size()) swap(s1, s2);  //假设s1和s2中，最短的字符是当前的最长公共前缀
        string str = s2.substr(0, s1.size());
        if(str == s1) return s1;
        else if(str[0]!=s1[0]) return "";
        else{
            for(int i=0; i<str.size(); i++){
                if(str[i] != s1[i]) return str.substr(0, i);
            }
        }
        // return "";
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==0) return "";
        if(n==1) return strs[0];
        string res=strs[0];
        for(int i=1; i<n; i++){// 遍历每一个字符串
            res = twoCommon(res, strs[i]);
            if(res=="") return res;
        }
        return res;
        
    }
};




// 二叉树

没看