#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> plusOne(vector<int>& digits){
        int index = digits.size()-1;
        int jin = 1;
        int cur = 0;
        for(int i=index; i>=0; i--){
            if(jin != 0){// 进位不等于0
                cur = (1+digits[i])%10;
                jin = (1+digits[i])/10;
                digits[i] = cur;
                if(jin == 0) return digits;//当前不产生进位  直接返回结果
                if(i==0){// 最前面如果需要进位的话，应该重新在数组最前面插入数据
                    digits.insert(digits.begin(), 1);
                        return digits;
                }
            }
            else return digits;
        }
    }
};
// ----下面是在讨论区看到的一种很有思路的解法
//void plusone(vector<int> &digits)
//{
//	int n = digits.size();
//	for (int i = n - 1; i >= 0; --i)
//	{
//		if (digits[i] == 9)
//		{
//			digits[i] = 0;
//		}
//		else
//		{
//			digits[i]++;
//			return;
//		}
//	}
//		digits[0] =1;
//		digits.push_back(0);
//
//}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
//            if(i==index){
//                cur = (1+digits[i])%10;
//                jin = (1+digits[i])/10;
//                digits[i] = cur;
//                if(jin == 0) return digits;
//            }
//            else{
//                if(jin!=0){
//                    cur = (jin+digits[i])%10;
//                    jin = (jin+digits[i])/10;
//                    digits[i] = cur
//                    if(jin==0) return digits;
//                    if(i==0){//不用再进位了  直接在前面插入1
//                        digits.insert(0, 1);
//                        return digits
//                    }
//                }
//            }
