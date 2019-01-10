class Solution {
public:
    int divide(int dividend, int divisor) {
        int res = 0;
        bool neg1=false, neg2=false;
        if(dividend < 0){
            neg1 = true;
            dividend = -dividend;
        }
        if(divisor < 0){
            neg2 = true;
            divisor = -divisor;
        }
        if(dividend - divisor < 0) return res;
        int a = dividend;
        int b = divisor;
        int flag = 1;
        int diff = dividend - divisor;
        while(a > b){
            flag = 1;
            while(a > b){
                b<<1;
                if(a < b) break;
                flag << 1;
            }
            b>>1;
            a = a - b;
            b = divisor;
            cout<<flag<<endl;;
            res += flag;
        }
        return res;    
    }
};