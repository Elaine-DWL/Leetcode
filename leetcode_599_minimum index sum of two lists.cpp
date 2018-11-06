class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp1, mp2;
        for(int i=0; i<list1.size(); i++){
            mp1[list1[i]]=i;
        }
        int min_index=0x7fffffff;
        string str="";
        vector<string> res;
        for(int i=0; i<list2.size(); i++){
            mp2[list2[i]]=i;
            if(mp1.count(list2[i])!=0){
                //str = (i+mp1[list2[i]])<min_index?list2[i]:str;
                min_index = min(i+mp1[list2[i]], min_index);
                
            }
        }
        for(int i=0; i<list2.size(); i++){
            if(mp1.count(list2[i])!=0 && i+mp1[list2[i]]==min_index)
                res.push_back(list2[i]);
        }
        return res;
    }
};