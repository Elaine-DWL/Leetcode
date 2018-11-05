#include <iostream>
#include<string>
using namespace std;
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int n = S.length();
        vector<vector<int>> res;
        for(int i=0; i<n;){
            if(i+2<=n-1 && S.at(i)==S.at(i+1) && S.at(i+2)==S.at(i)){
                int j=i+2;
                while(j<n && S[i]==S[j]) j++;
                vector<int> c({i,j-1});
                res.push_back(c);
                i=j;
                continue;
            }
            i++;
        }
        return res;
    }
};
// 上面自己写的代码 不够简洁
//  这是更简洁的版本。
vector<vector<int>> largeGroupPositions(string S) {
        int i = 0, j = 0, N = S.size();
        vector<vector<int>> res;
        while (j < N) {
            while (j < N && S[j] == S[i]) ++j;
            if (j - i >= 3) res.push_back({i, j - 1});
            i = j;
        }
        return res;
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
