// 别人的16ms
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int res = 0;
        while (dvd >= dvs) { 
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            res += multiple;
        }
        return sign == 1 ? res : -res; 
    }
};

// 自己看完上面的后  自己写的12ms
class Solution {
public:
    int divide(int dividend, int divisor) {
       if(divisor==0 || dividend==INT_MIN && divisor==-1) return INT_MAX;
        int sign = (dividend>0) ^ (divisor>0) ? -1 : 1;
        long dvd = labs(dividend);
        long dvr = labs(divisor);
        int res = 0;
        while(dvd >= dvr){ // 这里不要漏了 等于号
            long multiple = 1;
            long temp = dvr;
            while(dvd >= temp){
                temp = temp << 1;
                if(dvd < temp) break;
                multiple = multiple<<1;
            }
            temp = temp>>1;
            dvd -= temp;
            res += multiple;
        }
        return sign==1?res:-res;
    }
};