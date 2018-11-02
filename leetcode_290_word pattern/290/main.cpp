#include <iostream>

using namespace std;
class Solution{
public:
    bool wordPattern(string pattern, string str){
        unordered_map<char, int> p2i;
        unordered_map<string, int> s2i;
        istringstream in(str);
        string word;
        int i;
        for(i=0; in>>word; i++){
            if(i==pattern.size() || p2i[pattern[i]] != s2i[word]) return false;
            p2i[pattern[i]] = s2i[word] = i+1;
        }
        return i==pattern.size();
    }
};
// 方法2 双映射的建立
class Solution{
public:
    bool wordPattern(string pattern, string str){
        unordered_map<string, char> p;
        unordered_map<char, string> c;
        istringstream in(str);
        string word;
        int i=0;
        for(; in>>word; i++){
            if(i==pattern.size()) return false;
            if(p.count(word)==1 && c.count(pattern[i])==1){// 都存在映射
                if(p[word]==pattern[i] && c[pattern[i]]==word) continue;
                else return false;
            }
            else if(p.count(word)==0 && c.count(pattern[i])==0){
                p[word] = pattern[i];
                c[pattern[i]] = word;
            }
            else return false;

        }
        return i==pattern.size();

    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
