class Solution {
public:
    bool solve(int i,int j, auto&points){
        int lup=i;
        int rdp=j;
        if(points[j][0]<points[i][0] || (points[j][0]==points[i][0] && points[j][1]>points[i][1])) {
            lup=j;
            rdp=i;
        }
        if(points[lup][1]<points[rdp][1]) return false;

        for(int i=0; i<points.size(); i++){
            if(i==lup || i==rdp) continue;
            int x=points[i][0];
            int y=points[i][1];
            if(points[lup][0]<=x  && points[rdp][0]>=x){
                if(points[lup][1]>=y && points[rdp][1]<=y) return false;
            }

        }
        return true;




        

    }
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                bool ok=solve(i,j,points);
                if(ok) cnt++;
            }
        }
        return cnt;


        
    }
};