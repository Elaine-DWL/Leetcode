// 求一个string类字符串最后一个单词的长度
#include <iostream>
#include <string>
using namespace std;
//------思路(1)：调用string中相关函数。刚开始只考虑到很普通情况("","aa bbb"和"aa")，所以就是先找到最后一个空格的位置，然后用字符串长度-空格为位置-1
//------         这样的话就漏掉了("aa   ","aa  bbb  ")这样特殊的情况
//class Solution {
//public:
//    int lengthOfLastWord(string s) {
//        int tail = s.find_last_not_of(' ');//找到最后一个非空格的位置
//        if(tail == -1) return 0;
//        //从tail开始，逆向查找第一个空格
//        int head = s.rfind(' ',tail);
//        if(head == -1) return tail+1;
//        return tail-head;
//    }
//};

//-------思路(2):直接对数组进行操作
class Solution{
    int lengthOfLastWord(string s){
        if(s.size()==0) return 0;
        int tail = s.size()-1;
        while(tail>0 && s[tail]==' ') tail--;
        int head = tail;
        while(head>=0 && s[head]!=' ') head--;
        return tail-head;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
