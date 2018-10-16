#include <iostream>

using namespace std;
// 用哈希  来求排序后奇数位置的数之和
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int myhash[20001]={0};
        // 转化成哈希表存储
        for(int num:nums) myhash[num+10000]++;
        int flag=1;// 判断是不是奇数位 初始化是奇数位
        int sum=0;// 存储总和
        int cnt =0;// 存储当前已经累加的个数
        for(int i=0; i<20001&&cnt<nums.size();){// 遍历哈希表
            if(myhash[i]==0){//没有数则跳过 看后面一个
                i++;
                continue;
            }
            if(flag==0){// 虽然有数 但是它在偶数位 所以要看后面一个
                flag=1;
                myhash[i]--;
                if(myhash[i]==0) i++; // 如果没有重复数了
                continue;
            }
            if(myhash[i]>0 && flag==1){// 是奇数位则求和 并标记下一个为偶数
                sum += i-10000;//求和
                myhash[i]--;
                cnt++;
                flag = 0;//标记下次是偶数
                if(myhash[i]==0) i++;
            }
        }
        return sum;
    }
};

// 同样是哈希 人家的遍历部分比我的简单
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int hash[20001] = {0};

        for (int n : nums) {
            ++hash[n + 10000];
        }

        bool flag = true;
        int sum = 0;

        for (int i = 0; i < 20001; ++i) {
            if (flag == true) {
                sum += ((hash[i] + 1) / 2) * (i - 10000);
            } else {
                sum += (hash[i] / 2) * (i - 10000);
            }

            if ((hash[i] & 0x01) != 0) {
                flag = !flag;
            }
        }

        return sum;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
