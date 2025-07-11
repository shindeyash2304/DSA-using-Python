class Solution {
    private: 
    int f(vector<vector<int>> &mat, int row, int col, vector<vector<int>> &dp)
    {
        if(row >= mat.size() || col >= mat.size()) return 0; 
        if(dp[row][col] != -1) return dp[row][col] ;
        int ans = INT_MIN ;
        
        ans = mat[row][col] + max({f(mat, row, col + 1, dp), f(mat, row - 1, col  +1, dp), f(mat, row + 1, col + 1, dp)}) ;
        
        return dp[row][col] = ans; 
    }
    public:
    int maxGold(vector<vector<int>>& mat) {
        // code here
        int ans = INT_MIN ;
        vector<vector<int>> dp (mat.size(), vector<int> (mat.size(), -1)) ;
        for(int i = 0; i < mat.size(); i++)
        {
            ans = max(ans, f(mat, i, 0, dp)) ; 
        }
        return ans ;
    }
};