//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt(); // Number of test cases
        while (tc-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            char[][] mat = new char[n][m];

            // Reading the matrix
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    mat[i][j] = sc.next().charAt(0);
                }
            }

            String word = sc.next();
            Solution obj = new Solution();
            boolean ans = obj.isWordExist(mat, word);
            if (ans)
                System.out.println("true");
            else
                System.out.println("false");

            System.out.println("~");
        }
        sc.close();
    }
}
// } Driver Code Ends

class Solution {
    static public boolean isWordExist(char[][] mat, String word) {
        int n = mat.length;
        int m = mat[0].length;
        boolean[][] visited = new boolean[n][m];
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == word.charAt(0)) {
                    boolean ans = findWord(mat, word, 0, visited, i, j);
                    if(ans) return true;
                }
            }
        }
        
        return false;
    }
    
    public static boolean findWord(char[][] mat, String word, int pos,
        boolean[][] visited, int i, int j) {
            
            if(pos == word.length()) return true;
            
            if(i>mat.length-1 || j>mat[0].length-1 || i<0 || j<0 || word.charAt(pos) != mat[i][j] || visited[i][j]) 
                return false;
        
            visited[i][j] = true;
            
            boolean ans = findWord(mat, word, pos+1, visited, i+1, j)
                    || findWord(mat, word, pos+1, visited, i-1, j)
                    || findWord(mat, word, pos+1, visited, i, j+1)
                    || findWord(mat, word, pos+1, visited, i, j-1);
            
            visited[i][j] = false;
            return ans;
    }
}
