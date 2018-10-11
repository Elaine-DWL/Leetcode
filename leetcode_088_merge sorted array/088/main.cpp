// 题意是要求合并两个有序数组nums1和nums2 在nums1上操作  并假设nums1的空间足够大
#include <iostream>
#include <vector>

using namespace std;
// 这是自己的解法，还是依赖于掉用vector相关函数
// 思路就是，从小到大(从左往右)遍历nums2，然后nums1上有一个标记i,用于确定当前nums2[j]的位置。
// 因为用的insert函数，所以最后vector容器Nums1的大小会比以前大，所以还需要erase函数，删除后面的0
class Solution{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        for(int i=0,j=0; j<n; j++){
            while(i<m+j && nums1[i] <= nums2[j]) i++;
            nums1.insert(nums1.begin()+i, nums2[j]);
            i++;
        }
        nums1.erase(nums1.begin()+m+n, nums1.end());
    }
};
//  leetcode1 别人的优秀解法
// 这种思路是，nums1的大小是m+n,一开始nums1存储的数据有m个，
// 要把nums2数组中的数据按大小次序插入到nums1中.
// 从nums1的最后一个位置开始，比较mums2和nums1原始数据中最后两个数的大小，选取当前的最大的放在nums1的末尾
// 然后按这样的方法，挑选出次最大的放在nums1的倒数第二个位置。
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, tar = m + n - 1;
        while (j >= 0) {
            nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
    }
};
//---------------------------------leetcode2 和leetcode1其实是一种思路 但是比leetcode1写的更详细点，代码更好理解
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int r1 = m-1, r2 = n-1, r = m+n-1;
        while(r1>=0 && r2>=0)
            nums1[r--] = nums1[r1]>nums2[r2]? nums1[r1--] : nums2[r2--];
        while(r2 >= 0)
            nums1[r--] = nums2[r2--];
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
