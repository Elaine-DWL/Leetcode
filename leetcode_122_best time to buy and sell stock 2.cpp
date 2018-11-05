// 和121题一样，这道题的要求是可以进行多次买入和出售，
// 在每次买入新的袜子之前，必须把所有的袜子都卖掉
// 我刚开始的思路是，求出所有的极小值和极大值，然后从最左边的极小值开始，统计所有极大值-极小值的和
// 写代码的时候，求这个极大值和极小值的步骤比较繁琐，
// 在讨论区看到有大佬的解析是，假设a<b<c<d，那么d-a=(d-c)+(c-b)+(b-a);
// 所以说，要求极大值和极小值之差  可以直接统计递增区间的相邻元素差之和
#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    int maxProfit(vector<int>& prices){
        if(prices.size()/2==0) return 0;
        int maxprofit = 0;
        for(int i=1; i<prices.size(); i++){
           maxprofit += prices[i]>prices[i-1]?prices[i]-prices[i-1]:0;
        }
        return maxprofit;
    }
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
