// 股票买卖系列
// 有冷冻期  不限制交易次数
// DP问题 buy表示买入 sell表示卖出 rest表示冷冻期
// 用 buy[i]表示到第i天时，最后一次行为为buy的所有情况中收益的最大值, sell[i], rest[i]类似
// buy[i] = max(buy[i-1], rest[i-1]-prices[i])  即 max(第i天为rest，第i天为buy)
// sell[i] = max(sell[i-1], buy[i-1]+prices[i]) 即 max(第i天为rest，第i天为sell)
// rest[i] = max(buy[i-1], sell[i-1], rest[i-1])
// 上面三个式子可以保证 sell之前一定有buy    buy之前一定有rest
// 我们可以知道 rest[i] >= buy[i]   rest[i] <= sell[i]   所以式子三可以推断出: rest[i] = sell[i-1]
// 所以状态转移公式可以化成：
// buy[i] = max(buy[i-1], sell[i-2]-prices[i])
// sell[i] = max(sell[i-1], buy[i-1]+prices[i])
// 根据这两个状态转移方程可以写出下面代码：
// 思路一
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 冷冻期 
        int n = prices.size();
        if(n<=1) return 0;
        vector<int> buy(n, 0), sell(n, 0);
        buy[0] = -prices[0], sell[0] = 0;
        sell[1] = max(buy[0]+prices[1], sell[0]);
        buy[1] = max(-prices[0], -prices[1]);// 这里的初始条件很容易搞错
        for(int i=2; i<n; i++){
            buy[i] = max(sell[i-2]-prices[i], buy[i-1]);
            sell[i] = max(buy[i-1]+prices[i], sell[i-1]);
        }
        return sell[n-1];// 最大的收益  肯定是以sell结尾
    }
};

// 思路二
// buy[i] = max(buy[i-1], sell[i-2]-prices[i])
// sell[i] = max(sell[i-1], buy[i-1]+prices[i])
// 观察这两个状态方程，可以发现当前状态最多只与前2个状态有关   所有可以不用数组  空间复杂度由O(n)变成O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int pre_buy=-prices[0], buy=-prices[0], sell=0, pre_sell=0;
        for(int price:prices){
            pre_buy = buy;
            buy = max(buy, pre_sell-price);
            pre_sell = sell;// 注意这两条语句的顺序，因为当前循环中的pre_sell 是用来给下一次循环中计算buy的
            sell = max(sell, pre_buy+price);
        }
        return sell;
    }
};