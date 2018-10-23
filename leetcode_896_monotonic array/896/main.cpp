#include <iostream>

using namespace std;
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        if(n <= 2) return true;
        int t0 = A[1] - A[0];
        for(int i=1; i<n;){
            while(A[i]==A[i-1] && i!=n-1) i++;
            if((A[i] - A[i-1])*t0 < 0) return false;
            t0 = A[i] - A[i-1];
            i++;
        }
        return true;
    }
};

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool increasing;
        if(A[0] <= back(A)) increasing=true;
        else increasing=false;
        for(int i=1; i<A.size(); i++){
            if(increasing){
                if(A[i] < A[i-1]) return false;
            }
            else{
                if(A[i] > A[i-1]) return false;
            }
        }
        return true;
    }
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
