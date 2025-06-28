class Solution {
  public:
  
  
    int binary_srch(int element,vector<int>&b){
        int start=0;
        int end=b.size()-1;
        int latest=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(b[mid]<=element){
                start=mid+1;
                latest=mid;
            }
            else{
                end=mid-1;
            }
        }
        return latest;
    }
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        vector<int>result;
        sort(b.begin(),b.end());
        int n=a.size();
        for(int i=0;i<n;i++){
            int element=a[i];
            int idx=binary_srch(element,b);
            result.push_back(idx+1);
        }
        return result;
    }
};