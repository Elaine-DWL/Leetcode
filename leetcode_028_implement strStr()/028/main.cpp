//这道题是实现一个类似字符串查找函数，查找字符串b是否在字符串a中出现，
//是的话返回第一次出现的位置下标，不存在则返回-1 如果字符串b是空的就返回0
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        if(haystack.empty()) return -1;
        int len = needle.size();
        for(int i=0; i<haystack.size(); i++){
            if(haystack[i]==needle[0]){
                string str = haystack.substr(i, len);
                if(str==needle) return i;
            }
        }
        return -1;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
