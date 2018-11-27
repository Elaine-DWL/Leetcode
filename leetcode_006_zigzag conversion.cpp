// 思路一
class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> res(numRows);
        int p=0;
        bool jin=true;
       for(int i=0,p=0; p<s.size(); ){
           if(jin && i<numRows){
               res[i].push_back(s[p++]);
               i++;
           }
           else if(i==numRows){
               if(numRows>2) jin = false;
               i = numRows>2?i-2:0;
               // i = i-2;
               
           }
           else if(!jin && i>-1){
               res[i].push_back(s[p++]);
               i--;
           }
           else if(i==-1){
               jin = true;
               i = numRows>2?i+2:0;
               // i = i+2;
           }  
        }
        string str="";
        for(int i=0; i<numRows; i++){
            for(int j=0; j<res[i].size();j++)
                str =str + res[i][j];
        }
        return str;
        
    }
};


// 思路二 找规律的方法
class Solution{
public:
	string convert(string  s, int numRows){
		string result = "";
		if(numRows==1) return s;
		int step1, step2;
		int len = s.size();
		for(int i=0; i<numRows; i++){
			step1 = (numRows-i-1)*2;
			step2 = i*2;
			int pos = i;
			if(pos < len) result += s.at(pos);
			while(1){
				pos += step1;
				if(pos >= len) break;
				if(step1) result += s.at(pos);
				
				pos += step2;
				if(pos >= len) break;
				if(step2) result += s.at(pos);
			}
		}
		return result;
	}
};