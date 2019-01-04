class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size()==0) return res; // 特别要注意这里 如果原始字符串是空的话，返回的vector也必须是空的
											// 如果不加这句的话 会返回 [""] 程序报错
	   res.push_back("");// 
        string mp[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for(int i=0; i<digits.size(); i++){
            vector<string> str;
            for(int j=0; j<res.size(); j++){
                string chars=mp[digits[i] - '0'];
                for(int k=0; k<chars.size(); k++){
                    str.push_back(res[j]+chars[k]);
                }
            }
            res = str;
        }
        return res;
    }
};
