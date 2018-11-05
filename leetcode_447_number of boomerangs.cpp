// 方法一 
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        double sum=0;
        for(int i=0; i<points.size(); i++){
            unordered_map<double, int> dist;
            for(int j=0; j<points.size(); j++){
                if(i!=j){
                    double distance = pow(double(points[i].first-points[j].first),2.0) + pow(double(points[i].second-points[j].second), 2.0);
                    dist[distance]++;
                }
            }
            for(auto d:dist) sum += d.second*(d.second-1);
        }
        return sum;
    }
};