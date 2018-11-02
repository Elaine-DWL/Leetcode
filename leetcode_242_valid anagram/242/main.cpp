#include <iostream>

using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s==t) return true;
        return false;
    }
};
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> smp, tmp;
        for(char ch:s) smp[ch]++;
        for(char ch:t) tmp[ch]++;
        return smp==tmp;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
