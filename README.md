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

* 思路三【set_intersection】

用STL里面的`set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(res, res.begin())`，返回的是set。

## 350. 数组的交集 2【哈希】

**题意**

前一题(349)中，返回的数组交集元素只能出现1次。而本题中，如果某个元素同时在两个数组中出现的话，那么在交集中，它出现的次数也应该尽可能多。

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

## 409. 最长回文串【哈希】

**题意**

输入一个由小写或大写字母组成的字符串，输出由这些字符组成的最长回文串的长度。

**解法**

对于原来每个字符串中的每个字符，如果该字符个数为偶数，则可以全部用来构建回文串，如果该字符个数为奇数，则该数量减去一个，用来构建回文串。最后加入一个奇数字符来构成回文串。

```
Input:
"abbbccccdd"

Output:
9(bbbccccdd或abbccccdd)
```

* 思路一

先为字符串构建哈希表，用sum=0表示回文串的初始长度。然后遍历哈希表，如果值是偶数，则把该值加入到sum，如果是奇数，则把该值-1加入到sum中。最后，如果出现过奇数的话，返回sum+1，否则返回sum。

## 438. 字符串中所有的变位词【哈希、滑动窗口】

**题意**

输入一个字符串s和一个非空的字符串p，在s中找出所有p的变位词(anagram)的起始下标。

字符串p的变位词（anagram）指的是字符长度和内容和p一样但内部字符顺序不一样的字符串。比如说"abc", 
"bca", "cba"都是“acb”的谜。

```
Input:
s: "cbaebabacd" p: "abc"
Output:
[0, 6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Input:
s: "abab" p: "ab"
Output:
[0, 1, 2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
```

**解法**

* 思路一

算是暴力的解法吧。时间复杂度是O(n^2)。先构建p的哈希表。然后用大小等于p的滑动窗口在s上滑动，对每个窗口内的子字符串，对照哈希表，如果该窗口内各个字符的相应个数和p的相同，则说明该窗口内的子字符串是p的变位词。

* 思路二

在思路一上进行改进，用两个哈希表，分别记录p中字符个数，和s中前p.size()个字串的字符个数，然后对这两个哈希表进行比较，如果相同的话，则将下标0放入结果res中。然后遍历s中剩余的字符，每次右边新加入一个字符，然后去掉左边的一个旧的字符，每次再比较两个哈希表是否相同即可。

* 思路三（还不懂）

[别人的解法](https://www.cnblogs.com/grandyang/p/6014408.html)

## 447. Boomerangs的数量【哈希】

**题意**

输入平面内n个点的坐标，boomerangs指的是一组点(i, j, k)满足，i到j的距离等于i到k的距离。返回所有这样的boomerangs的个数。n<=500，点的坐标范围是[-10000, 10000]。

```
Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
```

**解法**

* 思路一

暴力法，时间复杂度是O(n^3)

* 思路二

先遍历每一个点，假设以该点作为i点，计算，其它所有点到该点的距离，如果有某个距离处的点有n(n>=2)个，则可以构成$n(n-1)$种对。时间复杂度O(n^2)

## 463. 岛屿的周长【暴力】

**题意**

输入一个二维的0-1矩阵表示地图，矩阵中每个元素表示一个cell。cell等于1代表陆地，0代表有水。岛屿由这些标记为1的cell组成，cell之间可以水平或者竖直连接，不能对角连接。岛屿完全由水环绕，且恰好只有一个岛屿。

假设岛屿中没有湖(也就是说并不存在为0的cell被1包围)，cell的边长都为1。矩阵的长和宽都不超过100。要求求出岛屿的周长。

**解法**

* 思路一

暴力法，时间复杂度O(n^2)。根据题意，可以先给原矩阵的周围加上一圈0生成一个新的矩阵。初始化sum=0，遍历这个新的矩阵，当遇到1时，判断其上、下、左、右四个位置的元素中0的个数，用sum对个数进行累加，最后返回sum。

## 500. 键盘行【哈希】

**题意**

输入一个由string组成的数组，输出所有满足要求的string。要求是：该string中每个字符都在键盘的同一行。

**解法**

* 思路一

直接哈希，将键盘中的字母分别映射到它们对应的行。然后遍历每个string，判断其中是否所有字符都在同一行。

## 575. 分发糖果【哈希】

**题意**

输入一个长度为偶数的整数数组，数组中不同的数字代表不同种类的糖果。每个数字代表一个该种类的糖果。你需要将这些糖果数量均等地分给弟弟和妹妹。求妹妹可以拿到的糖果种类数的最大值。

输入数组的长度是[2, 10000]且是整数。糖果的类别编号在[-100000, 100000]之间。

```
Input: candies = [1,1,2,2,3,3]
Output: 3
Input: candies = [1,1,2,3]
Output: 2
```

**解法**

* 思路一

糖果总数就是数组的大小n，因为妹妹能够分得一半的糖果，那么为了让妹妹分得的糖果总类别数更多，可以先每种糖果给妹妹分一个，这个过程中如果妹妹拿到的糖果数达到了n/2，那么返回n/2。如果妹妹每种类别都拿到了，但是还不够总数还不够n/2的话，这时妹妹的糖果总数就是她能拿到的最多类别数。这个过程中可以为糖果类别建立哈希表，分别存储每个类别的糖果总数。整个过程简述为，构建哈希表，然后遍历哈希表，时间复杂度为O(n)。

* 思路二

思路一中的时间复杂度虽然是O(n)，但是，实际上进行了两次for循环。可以在这个基础上改以下，在构建哈希表的过程中，如果当前键是新键，则给妹妹分配糖果，不是新键的话，正常建立哈希表，不用分糖果。这样就可以把两个for循环简化为一个了。

## 594. 最长的和谐子串【哈希】

**题意**

和谐子串的定义为：该数组中，最大值和最小值的差刚好为1。输入一个整数数组，找出所有字串中，最长的和谐子串的长度。输入数组的长度不超过20000.

```
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
```

**解法**

* 思路一

首先，要搞清楚这个子串的意思。子串中的元素不一定在原数组中是相邻的，但是它们之间相应的顺序应该和原来是一样的。

和谐子串要求其中的元素最大值和最小值相差为1。可以先给原数组用map(会自动排序)建立哈希表。然后遍历哈希表，如果相邻元素key值相差为1的话，则这两个元素可以构建和谐子串，长度为两个键值的和。比较这个长度和max_length的大小。在这个过程中不断更新max_length。

* 思路二

直接用unordered_map构建哈希表也是一样可以的。两次循环。

```cpp
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto i: nums)
            m[i]++;
        int res = 0;
        for(auto it:m)
            if(m.count(it.first-1)>0) // 注意这里只需要判断比当前数小1的数就行了，不然的话会重复计数
                res = max(res, it.second+m[it.first-1]);
        return res;
    }
```

* 思路二

在构建哈希表的同时进行统计。只需要一次循环。

```cpp
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>m;
        int res = 0;
        for(auto i: nums){
            m[i]++;
            if(m.count(i+1))
                res = max(res, m[i] + m[i+1]);
            if(m.count(i-1))
                res = max(res, m[i] + m[i-1]);
        }
        return res;        
    }
```
## 599. 两个列表的最小下标和【哈希】

**题意**

有两个元素类型为string的数组，分别表示Andy和Doris最喜爱的餐厅列表，她俩想要选一个餐厅就餐。要求找出这样一个餐厅，满足：A和D都喜欢，且在两个数组中的下标和是最小的。

注意，满足条件的餐厅可能有多个。

**解法**

* 思路一

先为其中一个数组构建好哈希表，键值是元素所在位置的下标。然后在为另一个数组构建哈希表的过程中判断当前元素是否在之前的数组中出现过，是的话，更新下标和的最小值min_length。然后随便遍历一个数组，判断元素是否在两个数组中都出现且键值之和等于min_length，加入结果容器中。

## 645. 集合中的错误【哈希】

**题意**

集合s最初包含1-n的中的所有整数，现在其中有一个元素重复了，且有一个元素消失了，找出这个重复元素和消失的元素。集合内元素是无序的。

**解法**

* 思路一

构建哈希表的过程中，同时统计所有元素的和sum，如果判断到某个元素出现了两次，该元素即为重复元素dup。另一个消失的元素是`n*(n+1)/2-sum+dup`。

* 思路二（位运算）

参见[discuss区](https://leetcode.com/problems/set-mismatch/discuss/105513/XOR-one-pass)

## 705. 设计哈希集合【哈希】

**题意**

设计一个哈希集合结构，不使用语言的内置哈希库函数。所有值的范围是[0, 1000000].

**解法**

* 思路一

用vector<int>，然后每次需要操作数据得时候先用find()贩毒案该数据是否存在。

* 思路二

用bool a[i]=true/false判断i是否在哈希表内，初始化a得大小为1000001。相比解法一，该解法是用空间换时间

## 706. 设计哈希表【哈希】

**题意**

设计一个哈希表结构，不允许使用内置的哈希表相关函数。所有键和值的范围都是是[0, 1000000].

**解法**

* 思路一

直接使用int a[1000001]来建立哈希表，初始化所有的值为-1.

## 720. 字典中最长的单词

**题意**

给一个由字符串单词组成的列表代表一个英文字典words，从其中找出长度最长的单词，该单词能由字典总其它的词组成。如果有多个可能的答案，返回字典序(a,b,c...)最小的那个单词。

**解法**



## 141. 判断链表是否含环【链表】

**题意**

判断一个链表是否含环。

**解法**

* 思路一

Floyd判圈算法，用两个指针，一个fast每次走两步，一个slow每次走一步，同时从链表头结点出发，如果某一时刻相遇了，则说明链表中含环，如果fast或fast->next为NULL，说明链表无环。

## 160. 链表的交点【链表】【哈希】

**题意**

找出两个单链表的交点。如下所示，返回指向c1的指针。没有交点则返回null， 要求时间复杂度是O(n)，空间复杂度是O(1)。

```
A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
```

**解法**

* 思路一

时间O(m+n)，空间O(1)

先分别从headA和headB开始遍历链表，计算遍历的长度len1和len2。

如果len1>len2，则让headA先走len1-len2步。判断headA和heaB是否相等，相等的话直接返回headA。否则headA和headB同时走，每走一步判断是否相等，是的话返回相交节点。如果都走到了链表最后，则说明没有交点。

len2>len1时的做法相似。

len2=len1时，则直接headA和headB同时走就行了。

* 思路二

时间O(m+n)，空间O(n)或O(m)

可以考虑借助哈希表来实现。首先遍历headA，为每个指针(地址)建立哈希表，然后遍历headB中每一个指针，比对哈希表。

* 思路三

```cpp
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *cur1 = headA, *cur2 = headB;
    while(cur1 != cur2){
        cur1 = cur1?cur1->next:headB;
        cur2 = cur2?cur2->next:headA;
    }
    return cur1;
}
```

## 203. 移除链表中的元素

**题意**

移除链表中所有值为val的元素。

**解法**

* 思路一

直接遍历链表，判断。

## 206. 链表反转

**题意**

实现链表的反转。

**解法**

* 思路一

用三个指针实现。

* 思路二

用递归的方法实现，代码简洁，很值得深入理解和思考。

```cpp
class Solution{
public:
	ListNode* reverseList(ListNode* head){
		if(!head || !(head->next)) return head; //返回空。
		ListNode *node = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return node;
	}
};
```

## 234. 回文链表

**题意**

判断一个单链表是否为回文链表。

**解法**

* 思路一

将链表内容放到数组里，再进行回文串的判断。空间复杂度是O(n)。

* 思路二

用快慢指针的方法，遍历一遍原来的链表，当fast指向最后一个元素时，slow刚好指向后半段链表。对后半段链表进行反转，然后同时遍历两段链表进行比较。空间复杂度是O(1)，时间取决于反转链表算法。

## 237. 删除链表中的节点

**题意**

函数输入参数只有一个，那就是需要删除的链表节点，其它啥都没有。在原来的链表结构中删除该节点。

**解法**

* 思路一

如果该节点是链表的最后一个节点，只需要将该节点free就行了。

否则，将该节点下一个节点的值赋值给当前节点，然后删除下一个节点。

## 876. 链表的中点

**题意**

当链表节点个数为奇数个时，返回指向第(n+1)/2个节点的指针。

当链表节点个数为偶数个时，返回指向第n/2+1个节点的指针。

**解法**

* 思路一

快慢指针。

## 070. 爬楼梯【动态规划】3

**题意**

你正在爬一个n阶的楼梯，每次可以走一步或两步，问共有多少种走法可以到达楼梯最顶端。

**解法**

* 思路一

用f(n)表示到达第n阶楼梯时的走法数，可以很容易得到状态转移方程$f(n)=f(n-1)+f(n-2)$，特别地，$f(1)=1$，$f(2)=2$。

可以用递归来实现，但是递归太深的话会导致栈溢出。

* 思路二

在求f(5)得时候，我们要求f(3)和f(4)，且求f(3)和f(4)的时候，我们都需要f(1)和f(2)的值。

可以换个思路，从f(3)开始，把每个f(i)都存起来，以后就不需要计算了，直接找就行。

## 198. 房屋抢劫【动态规划】【贪心】

**题意**

你是一个专业的强盗，并且计划去抢劫某条街道上的店铺。当某两个相邻的店铺都被闯入时，会触发自动报警。

输入一个非负整数的数组，每个元素代表相应位置的店铺的财产。在不触发警报的前提下，求出你能抢到的最多的财产数量。

**解法**

* 思路一

感觉是一种贪心的思想，用f(i)表示，当第i个位置是最后一家店时，所能抢到的最多财产数量；nums[i]表示第i家店里的财产数量。贪心的思想就是，尽可能抱枕f(i)最大。$f(i)=max(f(i-1), f(i-2)+nums(i)$

## 303. 范围总和查询-不可变的【哈希】【动态规划】

**题意**

给一个整数数组，找出下标i和下标j之间的元素的总和。

```
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
```

注意：

可以认为数组是不变的；

会对sumRange()函数进行多次调用。

**解法**

* 思路一

```cpp
class NumArray {
public:
    NumArray(vector<int> nums) {
        
    }
    
    int sumRange(int i, int j) {
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
```

leetcode里面自带的IDE预先输入了上面的代码，不是刚开始不是很懂怎么出来了一个构造函数，然后就按初始思路下了下面的代码，就是直接用循环来计算下标i和j之间元素的总和。

```cpp
class NumArray {
public:
    vector<int> nums;
    NumArray(vector<int> nums) {
        this->nums = nums;
    }
    
    int sumRange(int i, int j) {
        if(i<0 || j>nums.size()-1) return 0;
        int sum=0;
        for(int k=i; k<=j; k++){
            sum += nums[k];
        }
        return sum;
    }
};
```

submit以后，居然beat 1.46%....醉了。

还是要好好理解题意QAQ

* 思路二

现在重新对问题分析，题目的意思大概是，会调用一次构造函数生成数组，然后在**一个测试用例中**会多次调用求和函数sumRange()。按照思路一，每次调用sunRange()都会进行O(n)的复杂度来求和，导致冗余计算。

为什么不在构造函数中添加哈希表构建。用f[n]记录前n个数的和，那么求nums[i]~nums[j]之间的和，可以用f[j]-f[i]来计算。

提交显示，beat 86.03%。

## 003. 最长无重复子串【哈希】【滑动窗口】

**题意**

输入一个字符，返回它的最长无重复子串的长度。

注意：最长子序列和最长子串的区别。

```
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

**解法**

* 思路一

先在草稿纸上想一想，如果是手工来找，要怎么找呢。比如说查找序列`abcadcabb`的最长无重复子串，从第一个字符串开始，往后看第二个字符b，`ab`是无重复的，再看c，`abc`也没有重复，接下来到字符a，`abca`中字符a重复了，然后目前的基字符串就编程了`bca`，接着看后面的字符...

上述做法抽象一下，其实就是用一个滑动窗口在字符串上进行滑动，用哈希表hash记录字符最后出现的位置，可以用left、right指针分别表示滑动窗口的两端，right不断向右扩张，每次判断hash[right]的值是否在滑动窗口中(也就是判断新的字符是否在当前子串中出现过)，如果是的话，改变left指针的值，`left=hash[right]+1`，在这个过程中滑动窗口的长度就是无重复子串长度，不断更新滑动窗口长度的最大值。

## 009. 回文数的判断

**题意**

判断一个整数是否为回文数。

```
Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
```

**解法**

* 思路一

根据题目给出的例子，首先可以知道，负数绝对不是满足要求的回文数。[0, 9]之间的整数肯定是回文数。

用取余、取整的方法，将整数各个位上的数字抽取出来放入一个数组中。用两个指针(一头一尾)，通向遍历数组，当发现对应两个位置的数字不相等时，则不是回文数，返回false。

时间复杂度和原来整数的位数n有关。O(n+n/2)

* 思路二

用取余的方法抽取各个位置上数字的过程中，首先取出来的是低位的数字，每一次取新数字的时候，把res（初始为0）*10，再加上这个新数字。最后判断得到的逆序数res和原数字是否相等。

时间复杂仍然和整数的位数n有关。O(n)

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x/10 == 0) return true;
        vector<int> tmp;
        int y=x, res=0;
        while(y){
            res = res*10 + y%10;
            y = y/10;
        }
        return res==x;
    }
};
```

* 思路三

思路二中，是等所有数字逆序完来比较结果的，其实可以在逆序一半的时候就进行判断，比如说判断`123321`是否是回文数，可以在对后面三位数进行逆序后，判断得到的`123`和剩下的`123`比较是否相等。

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int sum=0;
        while(x>sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum)||(x==sum/10);
    }
};
```

## 069. 求$\sqrt{x}$的近似值

**题意**

输入x，返回$\sqrt{x}$的近似值(如果是小数的话，返回整数部分)。不能调用库函数。

```
Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
```

**解法**

* 思路一

二分搜索。