//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
        multiset<int>s;
        stack<int>st;
        
    Solution() {
        // code here
        
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        st.push(x);
        s.insert(x);
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(!st.empty()) {
            int x = st.top();
            st.pop();
            auto it = s.find(x);
            if(it != s.end()) s.erase(it);
        }
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        if(st.empty()) return -1;
        return st.top();
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(st.empty()) return -1;
        return *s.begin();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends