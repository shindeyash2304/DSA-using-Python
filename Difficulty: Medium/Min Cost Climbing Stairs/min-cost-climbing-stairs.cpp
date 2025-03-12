//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    int dp[100000];
    int solve(vector<int>& cost, int i){
        
        if(i >= cost.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int step1 = cost[i] + solve(cost,i+1);
        int step2 = cost[i] + solve(cost,i+2);
        
        return dp[i] = min(step1,step2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
      
      memset(dp,-1,sizeof(dp));
      int s1 = solve(cost,0);
      int s2 = solve(cost,1);
      
      return min(s1,s2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends