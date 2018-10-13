//对一个已排序的数组  找出两个元素，他们的和要等于目标值，返回这两个元素的下标

#include <iostream>
#include <vector>
using namespace std;
// 这是我刚开始的想法，借助find函数，完全是在调用stl，这样的速度特别慢 288ms
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
// ac了，速度是4ms   已经很快了
class Solution{
public:
    vector<int> twoSum(vector<int>& numbers, int target){
        map<int, int> myhash;
        for(int i=0; i< numbers.size(); i++){// 构建哈希表
            myhash[numbers[i]] = i+1;
        }
        for(int i=0; i<numbers.size(); i++){
            if(myhash.count(target-numbers[i]) != 0){
                return vector<int>{i+1, myhash[target-numbers[i]]}；
            }
        }
    }
};
//  第三种方法是在讨论区看到的 这种方法很容易看懂  但是我自己想真的想不出来
// 这个速度和上面哈希表差不多  但是这个空间复杂度比上面的小
class Solution{
public:
    vector<int> twoSum(vector<int>& numbers, int target){
        int p1=0, p2=numbers.size()-1;
        while(numbers[p1] + numbers[p2] != target){
            if(numbers[p1] + numbers[p2] < target) p1++;
            else p2--;
        }
        return vector<int>{p1+1, p2+1};
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
