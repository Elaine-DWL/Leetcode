// 思路一 自己的实现  4ms beat100%
class Solution {
public:
    // 在nums中进行二分查找   没找到就返回
    int binary_search(vector<int>& nums, int p, int q, int target){
        int p0=p;
        if(p>q) return -1;
        while(p<=q){
            int mid = (p+q)/2;
            if(target == nums[mid]) return mid-p0; // 返回的是相对于p0的偏置
            else if(target < nums[mid]) q=mid-1;
            else p=mid+1;
        }
        return -1;
    }
    // 在循环数组中进行查找  时间复杂度O(logn)

    int find(vector<int>& nums, int start, int end_, int target, int offset){// offset是当前的偏置
        int mid = (start + end_)/2;
        if(start > end_) return -1;
        if(target == nums[mid]) return offset+mid-start;
        if(nums[start]<=nums[mid] && nums[start]<=target && target<=nums[mid]){ // 左有序并且在左边  注意这里(nums[start]<=nums[mid])的等号如果去掉 则[3, 1]这种情况查找1时无法进到循环中会返回-1
            int t = binary_search(nums, start, mid-1, target);
            if(t==-1) return -1;
            else return offset + t;
        }
        else if(nums[mid]<=nums[end_] && nums[mid]<=target && target<=nums[end_]){// 右有序并且在右边
            int t = binary_search(nums, mid+1, end_, target);
            offset += mid-start+1;// //在右部分查找 offset要加上len(left)
            if(t==-1) return -1;
            else return offset + t;
        }
        else if(nums[start]<=nums[mid]){ // 左有序但是不在左边
            offset += mid-start+1; //在右部分查找 offset要加上len(left)
            return find(nums, mid+1, end_, target, offset);
        }
        else{// 右有序但是不在右边
            offset = offset; //在左部分查找 offset不变
            return find(nums, start, mid-1, target, offset);
        }
    }

    int search(vector<int>& nums, int target) {
        return find(nums, 0, nums.size()-1, target, 0);
    }
};
// 思路二






