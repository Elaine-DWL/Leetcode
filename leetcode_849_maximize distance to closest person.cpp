#include <iostream>

using namespace std;
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        int max_dist=1, sum=0;
        int i=0;
        if(seats[0]==0){//以0开头
            while(seats[i]==0){i++; sum++;}
            max_dist = sum;
        }
        int j=n-1;
        sum=0;
        if(seats[j]==0){// 以0结尾
            while(seats[j]==0){j--;sum++;}
            j++;
            max_dist = max(max_dist, sum);
        }
        sum=0;
        for(; i<=j; i++){
           // cout<<"i,j:"<<i<<","<<j<<endl;
            if(seats[i]==0) sum++;
            else{
                max_dist = max(max_dist, (sum+1)/2);
                sum=0;
            }
        }
        return max_dist;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
