class Solution {
public:
   typedef long long ll;
   int merge(int l, int r, int mid, auto&nums){
    int n1=mid-l+1;
    int n2=r-mid;
    int k=l;


    vector<ll>left(n1),right(n2);
    for(int i=0; i<n1; i++) left[i]=nums[l+i];
    for(int j=0; j<n2; j++) right[j]=nums[mid+1+j];

   

    int cnt=0,i=0,j=0;
    while(i<n1 && j<n2){
        if(left[i]>1LL*2*right[j]){
            cnt+=n1-i;
            
            j++;
        }
        else i++;
    }

    i=0,j=0;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            nums[k++]=left[i++];
        }
        else nums[k++]=right[j++];
    }
    while(i<n1){
        nums[k++]=left[i++];
    }
    while(j<n2){
        nums[k++]=right[j++];
    }

    return cnt;
 }
   int  mergeSort(int l, int r, auto&nums){
        if(l==r){
            return 0;
        }
        int mid=(l+r)/2;
        int left=mergeSort(l,mid,nums);
        int right=mergeSort(mid+1,r,nums);

        int cnt=merge(l,r,mid,nums);
        return cnt+left+right;



    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergeSort(0,n-1,nums);
        
    }
};