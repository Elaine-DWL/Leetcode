//这一题和118差不多  但是对空间复杂度有要求  o(n)
//之前是用一个二维数组来存储输出的，所以现在要变成一维数组来存储
//就是说从第一行开始每次在一维数组上。进行计算更新。
#include <iostream>
#include <vector>

using namespace std;
class Solution{
public:
    vector<int> getRow(int rowIndex){
        vector<int> res(rowIndex+1);
        res[0]=1;
        for(int i=1; i<= rowIndex; i++){
            for(int j=rowIndex; j>0; j--){
                res[j] = res[j-1] + res[j];
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
