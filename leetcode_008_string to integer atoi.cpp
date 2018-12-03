// 思路一
class Solution {
public:
    // 判断是否是数字
    bool isnum(char x){
        if(x<='9' && x>='0') return true;
        return false;
    }
    int myAtoi(string str) {
        int n = str.size();
        if(n==0) return 0;
        int res=0;
        bool first = false;
        int sign = 1;//符号
        int t;
        for(int i=0; i<n; i++){
            if(!first && str[i]==' ') continue;// 先把最前面的空格过滤
            if(!first){// 还是在找起始字符
                if(!isnum(str[i]) && (str[i]!='-') && (str[i]!='+')) return 0;
                else if(str[i]=='-') sign=-1;
                else if(str[i]=='+') sign=1;
                else{
                    res = str[i]-'0';
                }
                first = true;
            }
            else{
                if(!isnum(str[i])) break;
				// 判断溢出
				if(sign==1){
					if(res>INT_MAX/10 || (res==INT_MAX/10 && str[i]>'7')) return INT_MAX; //正数越界
				}
				else{
					if(res>INT_MAX/10 || (res==INT_MAX/10 && str[i]>'8')) return INT_MIN; //负数越界			
				}
                res = res*10 + (str[i]-'0');       
            }
        }
        res = sign * res;
        return res;
    }
};
// 思路二 讨论区看到的  简洁的写法
class Solution {
public:
    int myAtoi(string str) {
        if(str.size()==0) return 0;
        long result = 0;
        int indicator = 1;
        for(int i = 0; i<str.size();)
        {
            i = str.find_first_not_of(' ');
            if(str[i] == '-' || str[i] == '+')
                indicator = (str[i++] == '-')? -1 : 1;
            while('0'<= str[i] && str[i] <= '9') 
            {
                result = result*10 + (str[i++]-'0');
                if(result*indicator >= INT_MAX) return INT_MAX;
                if(result*indicator <= INT_MIN) return INT_MIN;                
            }
            return result*indicator;
        }
    }
};

