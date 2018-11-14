// 方法一
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x/10 == 0) return true;
        vector<int> tmp;
        int y = x;
        while(y){
            tmp.push_back(y%10);
            y /= 10;
        }
        int left = 0, right = tmp.size()-1;
        while(left<right){
            if(tmp[left]!=tmp[right]) return false;
            left ++;
            right --;
        }
        return true;
    }
};
// 方法二
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x/10 == 0) return true;
        vector<int> tmp;
        int y=x, res=0;
        while(y){
            res = res*10 + y%10;
            y = y/10;
        }
        return res==x;
    }
};


// 思路三
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int sum=0;
        while(x>sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum)||(x==sum/10);
    }
};
