#include <iostream>
#include <vector>
using namespace std;
// 20.58% 15/15 4ms
class Solution{
public:
    vector<vector<int>> generate(int numRows){
        vector<vector<int>> res(numRows);
        if(numRows==0) return res;
        res[0].push_back(1);
        for(int i=1; i<numRows; i++){//µÚiÐÐ
            for(int j=0;j<i+1;j++){
                if(j==0||j==i) res[i].push_back(1);
                else res[i].push_back(res[i-1][j-1]+res[i-1][j]);
            }
        }
        return res;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
