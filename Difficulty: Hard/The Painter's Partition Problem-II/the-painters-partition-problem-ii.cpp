class Solution {
private:
    bool check(int mid, vector<int>& arr, int k){
        int painter = 1;      // At least 1 painter needed
        int temp = 0;

        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > mid) return false;

            if(temp + arr[i] <= mid){
                temp += arr[i];
            }
            else{
                painter++;
                temp = arr[i];
            }
        }

        return painter <= k;
    }

public:
    int minTime(vector<int>& arr, int k) {
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans = high;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(check(mid, arr, k)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};