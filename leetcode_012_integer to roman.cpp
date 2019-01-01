
// 思路一  自己写的
// 整数转罗马数字
class Solution {
public:
    string intToRoman(int num) {
        map<int, string> mp;
        vector<int> a({1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000});
        string b[]={"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int n=a.size()-1;
        for(int i=0; i<=n; i++){
            mp[a[i]] = b[i];
        }
        
//         对于一个新来的数 num 现在要做的就是  依次判断能否被 a中的数整出
        string res="";
        while(num!=0 && n>-1){
            if(num/a[n] != 0){
                res += mp[a[n]];
                // cout<<mp[a[n]]<<endl;
                num -= a[n];
            }
            else n--;
        }
        return res;
        
    }
};




// 思路二  大神的java代码
public static String intToRoman(int num) {
    String M[] = {"", "M", "MM", "MMM"};
    String C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    String X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    String I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
}