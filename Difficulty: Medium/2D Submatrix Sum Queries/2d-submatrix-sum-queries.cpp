class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i = 1;i<n;i++){
            for(int j = 0;j<m;j++){
                mat[i][j] += mat[i-1][j];
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 1;j<m;j++){
                mat[i][j] += mat[i][j-1];
            }
        }

        vector<int> ans;
        
        for(auto &i : queries){
            int r1 = i[0], c1 = i[1], r2 = i[2], c2 = i[3];
            
            int mx = mat[r2][c2];
            int mn = 0;;
            
            if(r1>0 || c1>0){
                if(r1>0 && c1>0){
                    mn = mat[r1-1][c2] + mat[r2][c1-1] - mat[r1-1][c1-1];
                }
                else if(r1>0){
                    mn = mat[r1-1][c2];
                }
                else  mn = mat[r2][c1-1];
            }
            
            ans.push_back(mx-mn);
            
        }
        
        return ans;
    }
};