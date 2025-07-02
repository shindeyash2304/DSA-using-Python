class Solution {
  public:
    int totalElements(vector<int> &arr) {
        unordered_map<int, int> map;
        int i = 0;
        int j = 0;
        int ans = 0;
        
        while(j<arr.size()){
            map[arr[j]]++;
            
            while(map.size()>2){
                map[arr[i]]--;
                if (map[arr[i]] == 0) {
                    map.erase(arr[i]);
                }
                i++;
            }
            
            ans = max(ans,j-i+1);
            
            j++;
        }
        
        return ans;
    }
};