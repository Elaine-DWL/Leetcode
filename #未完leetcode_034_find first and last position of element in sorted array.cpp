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
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }
        return search(nums, target, 0, nums.size() - 1);
    }
private:
    vector<int> search(vector<int>& nums, int target, int l, int r) {
        if (nums[l] == target && nums[r] == target) {
            return {l, r};
        }
        if (nums[l] <= target && nums[r] >= target) {
            int m = l + (r - l) / 2;
            vector<int> left = search(nums, target, l, m), right = search(nums, target, m + 1, r);
            if (left[0] >= 0 && right[0] >= 0) {
                return {left[0], right[1]};
            }
            return left[0] == -1 ? right : left;
        }
        return {-1, -1};
    }
};