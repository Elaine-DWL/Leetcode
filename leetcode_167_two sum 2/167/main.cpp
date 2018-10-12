//对一个已排序的数组  找出两个元素，他们的和要等于目标值，返回这两个元素的下标

#include <iostream>
#include <vector>
using namespace std;
// 这是我刚开始的想法，借助find函数，完全是在调用stl，这样的速度特别慢
class Solution{
public:
    vector<int> twoSum(vector<int>& numbers, int target){
        for(int i=0; i<numbers.size(); i++){
            int p1 =find(numbers.begin()+i+1, numbers.end(),target-numbers[i]) - numbers.begin();
            if(p1 > 0 && p1!= numbers.size()){
                return vector<int>{i+1, p1+1};
            }
        }
    }
};


//想到用hash来做  刚开始就用数组来存储哈希表 但是，没有办法处理负数  所以要借用map来存储哈希表。
class Solution{
public:
    vector<int> twoSum(vector<int>& numbers, int target){
        vector<int> myhash(target+1, -1);
        for(int i=0; i< numbers.size(); i++){// 构建哈希表
            if(numbers[i] <= target)
                myhash[numbers[i]] = i+1;
        }
        for(int i=0; i<numbers.size(); i++){
            int t = myhash[target - numbers[i]];
            if(t!=-1){
                return vector<int>([i+1, t]);
            }
        }
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
