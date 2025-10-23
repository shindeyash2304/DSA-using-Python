class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int n = points.size();
        for(int i = 0;i<n;i++){
            int first = points[i][0];
            int second = points[i][1];
            first = first*1ll*first;
            second = second*1ll*second;
            int sum = first + second;
            pq.push({sum,i});
        }
        vector<vector<int>> ans;
        while(!pq.empty()&&k>0){
            int req = pq.top().second;
            pq.pop();
            k--;
            ans.push_back(points[req]);
        }
        return ans;
    }
};