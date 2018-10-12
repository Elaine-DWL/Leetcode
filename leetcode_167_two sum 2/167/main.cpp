//��һ�������������  �ҳ�����Ԫ�أ����ǵĺ�Ҫ����Ŀ��ֵ������������Ԫ�ص��±�

#include <iostream>
#include <vector>
using namespace std;
// �����Ҹտ�ʼ���뷨������find��������ȫ���ڵ���stl���������ٶ��ر���
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


//�뵽��hash����  �տ�ʼ�����������洢��ϣ�� ���ǣ�û�а취������  ����Ҫ����map���洢��ϣ��
class Solution{
public:
    vector<int> twoSum(vector<int>& numbers, int target){
        vector<int> myhash(target+1, -1);
        for(int i=0; i< numbers.size(); i++){// ������ϣ��
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
