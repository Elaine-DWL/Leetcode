// 自己写的
class Solution {
public:
    void memory(vector<int> &res, int t){
        if(res[0]==-1 && res[1]==-1){
            res[0] = t;
            res[1] = t;
        }
        if(t > res[1]){
            res[1] = t;
        }
        else if(t < res[0]){
            res[0] = t;
        }
        
    }
    void BinarySearch(vector<int> &res, vector<int> &nums, int l, int r, int target){
        if(l>r) return;
        int mid;
        while(l<=r){
            mid=(l+r)/2;
            if(nums[mid]==target){
                memory(res, mid);
                break;
            }
            if(nums[mid] < target) l = mid+1;
            else r = mid-1;
        }
        if(l>r) return;
        BinarySearch(res, nums, l, mid-1, target);
        BinarySearch(res, nums, mid+1, r, target);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2);
        res[0] = -1;
        res[1] = -1;
        int l=0, r=nums.size()-1;
        BinarySearch(res, nums, l, r, target);
        return res;
    }
};

// 思路二 使用STL中的equal_range()
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       pair<vector<int>::iterator, vector<int>::iterator> bounds = equal_range(nums.begin(), nums.end(), target);
        if(bounds.first == bounds.second)
            return {-1, -1};
        return {bounds.first-nums.begin(), bounds.second-nums.begin()-1};
    }
};

// 思路三 使用STL中的lower_bound()和upper_bound()
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>::iterator l = lower_bound(nums.begin(), nums.end(), target);
        vector<int>::iterator r = upper_bound(nums.begin(), nums.end(), target);
        if(l == r) return {-1, -1};
        return {l-nums.begin(), r-1-nums.begin()};
    }
};

// 思路四 分治法
class Solution {
public:
    // 分治法实现
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1, -1};
        return search(nums, 0, nums.size()-1, target);
    }
    vector<int> search(vector<int>& nums, int l, int r, int target){
        if(l>r) return {-1, -1};
        if(nums[l]==target && nums[r]==target) return {l, r};
        if(nums[l]<=target && target<=nums[r]){
            int m = (l+r)/2;
            if(nums[m] == target){
                vector<int> left = search(nums, l, m-1, target); //找到左半部分的区间
                vector<int> right = search(nums, m+1, r, target); //找到右半部分的区间
                int i=left[0]!=-1?left[0]:m; //如果左半部分的区间存在，则取其最小下标
                int j=right[1]!=-1?right[1]:m; //如果右半部分的区间存在，则取其最大下标
                return {i, j};
            }
            if(nums[m] < target) return search(nums, m+1, r, target);
            else return search(nums, l, m-1, target);
        }
        return {-1, -1};
    }
};