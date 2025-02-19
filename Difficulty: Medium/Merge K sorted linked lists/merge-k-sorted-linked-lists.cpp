//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        map<int,vector<Node*>> mp;
        int n =arr.size();
        for(int i =0;i< n;i++){
            Node* t = arr[i];
            while(t != nullptr){
                mp[t->data].push_back(t);
                t= t->next;
            }
        }
        auto x = mp.begin();
        Node* first = x->second[0];
        for(auto it = mp.begin(); it != mp.end(); it++) {
            vector<Node*>& curr_nodes = it->second;
            int n2 = curr_nodes.size();
            // Connect nodes with same value
            for(int i = 0; i < n2-1; i++) {
                curr_nodes[i]->next = curr_nodes[i+1];
            }
            // Connect to next value's nodes
            auto next_it = next(it);
            if(next_it != mp.end()) {
                curr_nodes[n2-1]->next = next_it->second[0];
            } else {
                curr_nodes[n2-1]->next = nullptr;
            }
        }
        return first;
    }
};


//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->next = newNode;
                temp = temp->next;
            }
            v[i] = head->next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends