//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int start=-1,end=-1;
        int maxLen=0;
        deque<int>mn,mx;
        for(int i=0,j=0;j<arr.size();j++){
            // finding min-element at the front of the deque:
            while(mn.size()>0 && arr[mn.back()]>arr[j]){
                mn.pop_back();
            }
            mn.push_back(j);
            // finding max-element at the front of the deque:
            while(mx.size()>0 && arr[mx.back()]<arr[j]){
                mx.pop_back();
            }
            mx.push_back(j);

            while(i<=j && mx.size()>0 && mn.size()>0 && (arr[mx.front()]-arr[mn.front()])>x){
               if(mx.size()>0 && mx.front()==i){
                   mx.pop_front();
               }
               if(mn.size()>0 && mn.front()==i){
                   mn.pop_front();
               }
               i++;
            }
            if(maxLen<(j-i+1)){
                start=i;
                end=j;
                maxLen=(j-i+1);
            }
        }
        vector<int>ans;
        for(int i=start;i<=end;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends