// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left=1, right=n;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(isBadVersion(mid)){// 如果这个是坏的
                right = mid-1;
            }
            else left=mid+1;
        }
        return right+1;
    }
};