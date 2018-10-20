#include <iostream>

using namespace std;
// f[i]代表当i为最后一个台阶时，所需要的最小代价和。
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n==2) return min(cost[0], cost[1]);
        vector<int> f(n);
        f[0] = cost[0];
        f[1] = min(cost[1], cost[0]+cost[1]);
        for(int i=2; i<n; i++){
            f[i] = cost[i] + min(f[i-1], f[i-2]);
        }
        int last = min(f[n-1], f[n-2]);
        return last;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
