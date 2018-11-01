# Shuati
找工作刷题集合

## 205. 字符串同构

### 题意

判断两个字符串是否具有相同的结构。

例如， 给定“egg”，“add”，返回真。 给定“foo”，“bar”，返回假。 给定“paper”，“title”，返回真。 

假设字符s和t具有相同的长度。

### 解法

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

