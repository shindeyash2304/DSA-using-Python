//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
        int i =0;
        if(n==1){
            return 0;
        }
        if(arr[i] == 0){
            return -1;
        }
         int jumps = 1;          
        int maxReach = arr[0];  
        int steps = arr[0];  
        
         for (int i = 1; i < n; i++) {
            if (i == n - 1) return jumps; // Reached the last index

            maxReach = max(maxReach, i + arr[i]); // Update max reachable index
            steps--; // Use a step

            if (steps == 0) { // If no steps left, we must jump
                jumps++;
                if (i >= maxReach) return -1; // If stuck, return -1
                steps = maxReach - i; // Reset steps to the new maxReach
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends