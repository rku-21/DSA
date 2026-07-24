class SegTree{
    private:
    vector<int>segment;
    int n;
    public:
    SegTree(int n){
       
        this->n=n;
        segment.resize(4*n,0);
    }
    int rangeQuery(int i, int l, int r, int start ,int end){
        if(l>end || r<start) return 0;

        else if(l>=start && r<=end) return segment[i];
         
         int mid=(l+r)/2;
         return rangeQuery(2*i+1,l,mid,start,end)+rangeQuery(2*i+2,mid+1,r,start,end);
    }
    int range(int start, int end){
        return rangeQuery(0,0,n-1,start,end);
    }
    void updateQuery(int i, int l, int r, int idx){
        if(l==r){
            segment[i]=1;
            return;
        }
        int mid=(l+r)/2;
        if(idx<=mid){
            updateQuery(2*i+1,l,mid,idx);
        }
        else updateQuery(2*i+2,mid+1,r,idx);

        segment[i]=segment[2*i+1]+segment[2*i+2];


    }
    void update(int idx){
        updateQuery(0,0,n-1,idx);
    }

};
class Solution {
public:
    typedef long long ll;
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
      
        int n=nums1.size();
        SegTree tree(n);
        int i=0;
        for(auto num:nums2){
            mp[num]=i;
            i++;
        }
        ll ans=0;
        for(int i=0; i<n; i++){
            int num=nums1[i];
            int leftCommonCnt=0;
            if(i==0 || mp[num]==0) leftCommonCnt=0;
            else leftCommonCnt=tree.range(0,mp[num]-1);

            int leftUncommonCnt=i-leftCommonCnt;

            int rightCommonCnt=n-mp[num]-1-leftUncommonCnt;

            ans+=(ll)leftCommonCnt*rightCommonCnt;

            tree.update(mp[num]);


        }

        return ans;





        
        
    }
};