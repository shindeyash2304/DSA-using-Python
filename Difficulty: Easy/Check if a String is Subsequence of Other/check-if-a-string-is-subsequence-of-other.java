class Solution {
    public boolean isSubSeq(String s1, String s2) 
    {
        int n = s1.length(), m = s2.length(), i = 0, j = 0;
        
        while(i<n && j<m) {
            if(s1.charAt(i) == s2.charAt(j))    i++;
            
            j++;
        }
        
        return i==n;
    }
};