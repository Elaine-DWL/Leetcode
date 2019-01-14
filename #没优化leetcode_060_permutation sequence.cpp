// 思路一  直接调用next_permutation()
class Solution {
public:
    string getPermutation(int n, int k) {
        string res="";
        for(int i=0; i<n; i++){
            res = res + to_string(i+1); 
        }
        for(int i=0; i<k-1; i++){
            next_permutation(begin(res), end(res));
        }
        return res;
        
    }
};