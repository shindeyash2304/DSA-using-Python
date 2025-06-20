class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n=arr.size(),c=0;
        queue<int> p,t;
        for(int i=0;i<n;i++) {
            if(arr[i]=='P') p.push(i);
            else t.push(i);
            while(p.size() and t.size()) {
                while(p.size() and t.size() and p.front()-t.front()>k) t.pop();
                while(p.size() and t.size() and t.front()-p.front()>k) p.pop();
                if(p.size() and t.size()) {
                    t.pop();
                    p.pop();
                    c++;
                }
            }
        }
        return c;
    }
};