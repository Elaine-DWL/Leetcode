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

