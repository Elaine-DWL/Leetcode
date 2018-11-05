// 题意是要求一个数组中a[j]-a[i]的最大值，j>=i;
// 可以用暴力法
#include <iostream>
#include <vector>
using namespace std;
// --------------直接暴力求解 200/200 耗时484ms  8.88% 时间复杂度是o(n*n)
class Solution{
public:
    int maxProfit(vector<int>& prices){
        int t = 0;
        for(int i=0; i<prices.size(); i++){
            for(int j=i; j<prices.size(); j++){
                t = prices[j]-prices[i]>t?prices[j]-prices[i]:t;
            }
        }
        return t;
    }
};
// ------------  另外一种思想是动态规划  maxprofit[i]表示在第i天卖出去(要在第i天或之前买入)的话所能产生的最大收益
//      maxprofit[i]=max{price[i]-minprice[i], maxprofit[i-1] } minprice[i]表示前天中的最小价格
//     时间o(n)   4ms 99.54% 200/200
class Solution{
public:
    int maxProfit(vector<int>& prices){
        int maxprofit=0;
        int minprice=prices[0];
        for(int i=0; i<prices.size();i++){
            minprice = prices[i]<minprice?prices[i]:minprice;
            maxprofit = prices[i]-minprice>maxprofit?prices[i]-minprice:maxprofit;
        }
        return maxprofit;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
