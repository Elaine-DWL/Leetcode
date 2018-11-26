// 思路二
class Solution{
public:
	int reverse(int x){
		long long res = 0;
		bool isPositive = true;
		if(x<0){
			isPositive = false;
			x = -x;
		}
		while(x>0){
			res = res * 10 + x%10;
			x /= 10;
		}
		if(res > INT_MAX) return 0;
		if(isPositive) return res;
		else return -res;
	}
}
// 思路二
class Solution{
public:
	int reverse(int x){
		int res = 0;
		while(x!=0){
			if(abs(res) > INT_MAX/10) return 0;
			res = res*10 + x%10;
			x /= 10;
		}
		return res;
	}
};

