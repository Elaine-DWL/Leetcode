#include <iostream>

using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int p1=0, p2=A.size()-1;
        while(p1<=p2){
            while(p1%2==0 && p1<=p2) p1++;
            while(p2%2==1 && p1<=p2) p2++;
            swap(A[p1], A[p2]);
        }
        return A;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
