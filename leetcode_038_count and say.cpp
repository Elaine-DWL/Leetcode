class Solution {
public:
    string countAndSay(int n) {
        if(n==0) return "";
        string cur = "1";
        string res = "1";
        while(--n){
            // 遍历前面的字符串 cur
            res = "";
            int cnt = 0;
            for(int i=0; i<cur.size();){
                cnt = 1;
                i++;
                while(i<cur.size() && cur[i]==cur[i-1]){
                    cnt++;
                    i++;
                }
                res = res + to_string(cnt);
                res.push_back(cur[i-1]);
            }
            cur = res;
        }
        return res;
    }
};