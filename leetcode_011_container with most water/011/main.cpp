#include <iostream>

using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left=0, right=n-1;
        int max_area = 0,
        while(left < right){
            max_area = max((right-left) * min(height[right], height[left]), max_area);
            if(height[right] < height[left]) right--;
            else left++;
        }
        return max_area;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
