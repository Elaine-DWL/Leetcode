// 括号匹配
class Solution {
public:
    bool isValid(string s) {
        if(s.size()==0) return true;
        map<char, char> mp2;
        mp2[')'] = '(';
        mp2['}'] = '{';
        mp2[']'] = '[';
        stack<char> cstack;
        for(int i=0; i<s.size(); i++){
            if(mp2.count(s[i])!=0){ // 如果是第二个 
                if(!cstack.empty() && cstack.top()==mp2[s[i]]){
                    cstack.pop();
                    continue;
                }
                else return false;
            }
            else
                cstack.push(s[i]);
        }
        if(!cstack.empty()) return false;
        return true;
    }
};