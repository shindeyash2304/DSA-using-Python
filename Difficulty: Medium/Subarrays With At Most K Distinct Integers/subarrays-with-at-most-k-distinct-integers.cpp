class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        int ct = 0,i = 0 , j = 0 , n = arr.size();
        map<int,int>mp;
        while(j < n){
            mp[arr[j]]++;
            if(mp.size() <= k){
                j++;
            }
            else{
                while(mp.size() > k){
                    ct += (n-j);
                    mp[arr[i]]--;
                    if(mp[arr[i]] == 0){
                        mp.erase(arr[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return (n*(n+1))/2 - ct;
    }
};