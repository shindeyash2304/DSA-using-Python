//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int maximumNonAdjacentSum(vector<int>&nums){
      int n = nums.size();
      int prev = nums[0];
      int prev2 = 0;
      for(int i=0;i<n;i++){
          int take = nums[i];
          if(i>1) take+=prev2;
          int notTake = prev;
          int curi = max(take,notTake);
          prev2 = prev;
          prev = curi;
      }
      return prev;
  }
    int maxValue(vector<int>& arr) {
        vector<int>temp1,temp2;
        int n = arr.size();
        if(n == 1) return arr[0];
        
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(arr[i]);
            if(i!=n-1) temp2.push_back(arr[i]);
        }
        return max(maximumNonAdjacentSum(temp1),maximumNonAdjacentSum(temp2));
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends