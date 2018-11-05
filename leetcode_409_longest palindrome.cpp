#include <iostream>

using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for(char ch:s) mp[ch]++;
        int sum=0;
        int flag=0;
        for(auto m:mp){
            if(m.second%2==0) sum += m.second;
            else{
                flag=1;
                sum += m.second-1;
            }
        }
        if(flag==1) return sum+1;
        else return sum;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
