#include <iostream>

using namespace std;
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> mp_A, mp_B;
        int sum_A=0, sum_B=0;
        for(int num:A){
            sum_A += num;
            mp_A[num]++;
        }
        for(int num:B){
            sum_B += num;
            mp_B[num]++;
        }
        for(auto num:B){
            int t = (sum_A+2*b-sum_B)/2;
            if(mp.count(t)) return vector<int>({t, num});
        }
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
