class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n/2==0) return n;
        int a[256];// 哈希表用来存储某字符最后一次出现的下标
        memset(a, -1, 256*sizeof(int));
        int left = 0;
        int max_len=1;
        a[s[0]]=0;
        for(int i=1; i<n; i++){
            if(a[s[i]]>=left){// 当前数曾经出现过，且在滑动窗口内
                left = a[s[i]]+1;
            }
            a[s[i]]=i;
            max_len=max(max_len, i-left+1);
        }
        return max_len;
    }
};