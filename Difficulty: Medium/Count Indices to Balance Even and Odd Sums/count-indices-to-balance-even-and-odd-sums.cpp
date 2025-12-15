class Solution {
  public:
    int cntWays(vector<int>& arr) {
        int n = arr.size();
        int o1 = 0, e1 = 0;
        
        for(int i = 0;i<n;i++){
            if(i%2==0) e1 += arr[i];
            else o1 += arr[i];
        }
        
        int ans = 0, o2 = 0, e2 = 0;
        
        
        for(int i = n-1;i>=0;i--){
            int x = (e1 - e2) + o2;
            int y = (o1 - o2) + e2;
            if(i%2==0){
                x -= arr[i];
                e2 += arr[i];
            }
            else {
                y -= arr[i];
                o2 += arr[i];
            }
            
            if(x==y) ans++;
        }
        
        return ans;
    }
};