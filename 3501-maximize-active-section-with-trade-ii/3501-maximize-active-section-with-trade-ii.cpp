class Tree {
    public:
    vector<int>segment;
    int n;
    Tree(auto & nums){
        int n=nums.size();
        this->n=n;
        segment.resize(4*n,0);

        BuildTree(0,n-1,0,nums);


    }

    void BuildTree(int i , int r, int l,auto& nums){

        if(l==r) {
            segment[i]=nums[l];
            return;
        }
        int mid=(l+r)/2;
        BuildTree(2*i+1,mid,l,nums);
        BuildTree(2*i+2,r,mid+1,nums);

        segment[i]=max(segment[2*i+1],segment[2*i+2]);
    }

    int  rangeMaxQuery(int i, int l, int r,int start, int end){
        if(l>end || r<start) {
            return 0;
        }

        if(l>=start && r<=end){
            return segment[i];
        }

        int mid=(l+r)/2;

        int left=rangeMaxQuery(2*i+1,l,mid, start,end);
        int right=rangeMaxQuery(2*i+2,mid+1,r,start,end);

        return max(left,right);



    }

    int rangeMax(int l , int r){
        return rangeMaxQuery(0,0,n-1,l,r);
    }
};





class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int>blockStart,blockEnd,blockSize;
        int activeOnes=0;
        for(int i=0; i<n; i++) if(s[i]=='1') activeOnes++;
        int i=0;
        while(i<n){
           if(s[i]=='0'){
            int start=i;
            while(i<n && s[i]=='0') i++;
            blockStart.push_back(start);
            blockEnd.push_back(i-1);
            blockSize.push_back(i-start);
        }
        else i++;
        }

        vector<int>pairSum;
        int m=blockSize.size();
        for(int i=0; i<m-1; i++){
            pairSum.push_back(blockSize[i]+blockSize[i+1]);
        }

        if(m<2){
            return vector<int>(queries.size(),activeOnes);
        }

        Tree tree(pairSum);
        vector<int>ans;

        for(auto q:queries) {
            int l=q[0];
            int r=q[1];

           

            auto  startBlock=lower_bound(blockEnd.begin(),blockEnd.end(),l);
            if(startBlock==blockEnd.end()) {
                ans.push_back(activeOnes);
                continue;
            }

            auto endBlock=upper_bound(blockStart.begin(),blockStart.end(),r);
         

            int startBlockIdx=startBlock-blockEnd.begin();
            int endBlockIdx=endBlock-blockStart.begin()-1;

            int maxPairsum=0;

           if(endBlockIdx>startBlockIdx){
              int firstlen=blockEnd[startBlockIdx]-max(l,blockStart[startBlockIdx])+1;
              int lastlen=min(r,blockEnd[endBlockIdx])-blockStart[endBlockIdx]+1;

            if(endBlockIdx-startBlockIdx==1){
               maxPairsum=firstlen+lastlen;
            }
            else {
                int pair1=firstlen+blockSize[startBlockIdx+1];
                int pair2=lastlen+blockSize[endBlockIdx-1];
                int RmqMax=tree.rangeMax(startBlockIdx+1,endBlockIdx-2);
                maxPairsum=max({pair1,pair2,RmqMax});
            }
        }

         ans.push_back(maxPairsum+activeOnes);
    }

    return ans;

 }
};