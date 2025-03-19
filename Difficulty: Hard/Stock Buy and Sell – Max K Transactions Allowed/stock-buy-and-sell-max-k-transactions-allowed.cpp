//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int fun(int i, int t, int hold, int &n, int &k, vector<int> &a,vector<vector<vector<int>>> &dp){
        if(i>=n || t>=k)
            return 0;
        if(dp[i][t][hold] != -1)
            return dp[i][t][hold];
            
        if(!hold){
            int buy = -a[i] + fun(i+1, t, 1, n, k, a, dp);
            int not_buy = fun(i+1, t, 0, n, k, a, dp);
            
            return dp[i][t][hold] = max(buy, not_buy);
        }
        else{
            int sell = a[i] + fun(i+1, t+1, 0, n, k, a, dp);
            int not_sell = fun(i+1, t, 1, n, k, a, dp);
            return dp[i][t][hold] = max(sell, not_sell);
        }    
            
    }
  
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2, -1)));
        
        return fun(0, 0, 0, n, k, prices, dp);
    }
};



//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends