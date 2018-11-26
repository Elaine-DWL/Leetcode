// 思路一 动态规划
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<=1) return s;
        vector<vector<bool>> flag(n, vector<bool>(n, false));
        int max_len=1, ind_i=0, ind_j=0;
        for(int i=0; i<n-1; i++){
            if(s[i]==s[i+1]){
                max_len = 2;
                ind_i = i;
                ind_j = i+1;
            }
            flag[i][i+1] = (s[i]==s[i+1]);
            flag[i][i] = true;
        }
        flag[n-1][n-1] = true;
        
        for(int j=2; j<n; j++){
            for(int i=0; i<j-1; i++){
                bool t = flag[i+1][j-1] && s[i]==s[j];
                flag[i][j] = t;
                if(t && j-i+1>max_len){
                    max_len = j-i+1;
                    ind_i = i;
                    ind_j = j;
                } 
            }
        }
        
        // cout<<ind_i<<" "<<ind_j<<endl;
            return s.substr(ind_i, ind_j-ind_i+1);
        return  "";
        
    }
};