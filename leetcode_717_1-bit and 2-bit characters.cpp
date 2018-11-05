#include <iostream>

using namespace std;
// 方法一
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int t;
        for(int i=0; i<bits.size();){
            if(bits[i]==1) {
                i += 2;
                t = 2;
            }
            else{
                i++;
                t=1;
            }
        }
        return t==1;
    }
};
// 方法二
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int cnt = 0;
        for(int i=bits.size()-2; i>=0; i--){
            if(bits[i] == 0) break;
            cnt++;
        }
        return cnt%2==0;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
