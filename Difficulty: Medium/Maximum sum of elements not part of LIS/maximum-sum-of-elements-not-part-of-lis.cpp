class Solution {
  public:
    int BinarySearch(vector<int> &arr, int val){
        int n = arr.size();
        int l = 0, r = n-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(arr[m]>=val){
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        return l;
    }
    int nonLisMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> lis, insert_idx(n);
        int sum = 0;
        
        for(int i = 0;i<n;i++){
            int val = arr[i];
            sum+= val;
            
            int idx = BinarySearch(lis, val);
            if(idx == lis.size()){
                lis.push_back(val);
                insert_idx[i] = lis.size();
            }
            else{
                lis[idx] = val;
                insert_idx[i] = idx + 1;
            }
        }
        
        int currlen = lis.size();
        for(int i = n-1;i>=0;i--){
            if(insert_idx[i] == currlen){
                sum -= arr[i];
                currlen--;
            }
        }
        
        return sum;
    }
};