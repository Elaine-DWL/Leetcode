class Solution {
public:
    string reverseString(string s) {
        int n = s.size();
        if(n/2==0) return s;
        for(int i=0; i<n/2; i++){
            int t=s[i];
            s[i] = s[n-1-i];
            s[n-1-i]=t;
            // swap(s[i], s[n-1-i]);
        }
        return s;
    }
};