[TOC]

# Shuati

找工作刷题集合

## 205. 字符串同构【哈希】

**题意**

判断两个字符串是否具有相同的结构。

例如， 给定“egg”，“add”，返回真。 给定“foo”，“bar”，返回假。 给定“paper”，“title”，返回真。 

假设字符s和t具有相同的长度。

**解法**

* 思路一

将字符串转化成数字序列.
"egg" --> [0, 1, 1]
"paper" --> [0, 1, 0, 2, 3]
上面这个过程可以借助哈希表来实现，然后判断字符串s和t生成的矩阵序列是否相等。

* 思路2

简单粗暴上代码：

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};
```

## 242. 字符串变位词的判断【哈希】

**题意**

输入两个字符串s和t，t是不是s的一个变位次。

比如说：s="anagram", t="nagaram", 是；s="rat", t="car", 不是

假定字符串中只有小写字母。

**解法**

* 思路一

将s和t各自内部排序后判断是否相等。

* 思路二

分别为s和t构建哈希表，判断两个哈希表是否相等。

* 思路三

先为s构建哈希表，然后在为t构建哈希表的过程中，是对键值进行-1操作。所以整个过程中只需要一个哈希表，最后判断哈希表中是不是所有元素都为0。

## 290. 单词模式串【哈希】

**题意**

给出一个模式`patter`和一个字符串`str`，判断该字符串是否是该模式。

```
Input: pattern = "abba", str = "dog cat cat dog"
Output: true
```

```
Input:pattern = "abba", str = "dog cat cat fish"
Output: false
```

```
Input: pattern = "abba", str = "dog dog dog dog"
Output: false
```

**解法**

* 思路一

使用双映射关系。同时遍历pattern的每个字符和str中的每个word，建立他们之间的映射关系，当出现违背映射关系的情况时，可以直接返回false。`map<string, char> s`和`map<char, string> p `

* 思路二(没写代码)

对于pattern和str，分别用一个数字记录每个字符或word第一次出现的位置。当同时遍历pattern和str时，如果发现它们在某一位置的字符或word第一次出现的位置不同，则返回false。

* 思路三(简洁代码，还没看懂)

```cpp
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
```

## 349. 数组的交集【哈希】

**题意**

输入两个数组nums1和nums2，输出它们的交集元素。

**解法**

* 思路一

首先为第一个数组建立哈希表，然后遍历第二个数组中的元素，如果该元素在哈希表中存在且键值大于0，则将该元素放入交集中且将它的键值改为-1（为了保证当集合元素不唯一时，不会重复计算交集）。

* 思路二【set】

其实本质上和思路一差不多。首先，构造用nums1构造一个set，然后遍历nums2，如果能在set中找到当前元素，则将该元素放到要返回的vector中，并且在set中删除该元素。

## 350. 数组的交集 2【哈希】

**题意**

前一题(349)中，返回的数组交集元素只能出现依次。而本题中，如果某个元素同时在两个数组中出现的话，那么在交集中，它出现的次数也应该尽可能多。

对于 Input: nums1 = [1,2,2,1], nums2 = [2,2]

本题 Output: [2,2]      349题 Output: [2]

**解法**

* 思路一

和前一题的思路一基本一致，但是：首先为第一个数组建立哈希表，然后遍历第二个数组中的元素，如果该元素在哈希表中存在且键值大于0，则将该元素放入交集中且将它的键值-1。

* 思路二

```cpp
vector<int> intersect(vector<int>& a, vector<int>& b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    a.erase(set_intersection(a.begin(), a.end(), b.begin(), b.end(), a.begin()), a.end());
    return a;
}
```

## 387. 字符串中第一个非重复字符【哈希】

**题意**

输入一个字符串，判断第一个只出现过一次的字符的下标。如果不存在这样的字符，则返回-2。

```
s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
```

假设字符串中只包含小写字母。

**解法**

* 思路一

用数组来建立哈希表。键值是每个字符出现的次数。然后遍历字符中每个字符，比对哈希表中的键值，如果等于1的话，则输出当前下标。最后跳出了遍历循环的话，就返回1，说明没有满足要求的字符。（能用数组建立哈希表的话就尽量用数组，因为map更耗时）。时间复杂度O(n)

* 思路二

用`unordered_map<int, pair<int, int>> mp;`来遍历字符串中的字符建立哈希，pair中的2个int分别代表当前key出现的次数，和第一次出现的位置。然后遍历生成的哈希表，找出仅出现一次且最先出现的字符的位置。

## 389. 找字符串的差异【哈希】

**题意**

输入两个字符串s和t，t中的字符是s中字符的乱序，且另外在随机位置随机添加了一个字符。要求输出这个被添加的字符。字符串由小写字母组成。

**解法**

* 思路一

首先为s构建哈希表`int mp[256]={0}`，键值表示的是该字符在s中出现的次数。然后遍历字符串t，如果当前字符没有在哈希表中出现(`mp[ch]==0`)，则返回该字符。否则的话`mp[ch]--`，因为新增的字符可能在s中曾出现多次。比如`s="ab",t="aab" `.

* 思路二

现对s中所有字符求和(ASCII求和)，然后对t中的所有字符求和，它们的差就是那个新添的字符。

* 思路三【位运算】

```cpp
class Solution {
public:
    char findTheDifference(string s, string t) {
        char r=0;
        for(char c:s) r ^=c;
        for(char c:t) r ^=c;
        return r;
    }
};
```

