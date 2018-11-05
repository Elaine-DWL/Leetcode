// 方法一 哈希
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int mp[256]={0};
        string s1="qwertyuiopQWERTYUIOP";
        string s2 = "asdfghjklASDFGHJKL";
        string s3 = "zxcvbnmZXCVBNM";
        for(char ch:s1) mp[ch]=1;
        for(char ch:s2) mp[ch]=2;
        for(char ch:s3) mp[ch]=3;
        vector<string> res;
        for(string word:words){
            int row = mp[word[0]];
            bool flag=false;
            for(char ch:word){
                if(mp[ch] != row){
                    flag = true;
                    break;
                }   
            }
            if(!flag) res.push_back(word);
        }
        return res;
            
    }
};