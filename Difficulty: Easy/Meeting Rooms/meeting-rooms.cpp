class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        sort(arr.begin(), arr.end());
        map<int,int>mpp;
        for(auto it : arr){
            mpp[it[0]]++;
            mpp[it[1]]--;
        }
        int sum = 0;
        for(auto it : mpp){
            sum+=it.second;
            if(sum > 1)return false;
        }
        return true;
    }
};

