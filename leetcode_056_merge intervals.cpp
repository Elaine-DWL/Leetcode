bool cmp(Interval a, Interval b){
        return a.start < b.start;
    }
class Solution {
public:
    
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size()<=1) return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> res;
        res.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            // 和res的最后一个比较
            int s1=intervals[i].start, s2=res[res.size()-1].start;
            int e1=intervals[i].end,  e2=res[res.size()-1].end;
            if(s1 > e2){ //没有交集
                res.push_back(intervals[i]);
            }
            else if(s1 == e2){// 刚好拼接
                res[res.size()-1].end = e1;
            }
            else{// s1<e2
                res[res.size()-1].start = min(s1, s2);
                res[res.size()-1].end = max(e1, e2);
            }
        }
        return res;
        
    }
};