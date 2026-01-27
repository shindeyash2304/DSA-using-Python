class Solution {
    
    boolean found;
    int m;//row
    int n;//col
    
    public void search(int r , int c , char[][] mat , boolean[][] visited , StringBuilder str , String word){
        if(str.length() >= word.length()){
            if(str.toString().equals(word)){
                
                found = true;
            }
            return;
        }
        
        int[][] neighbours = {{r - 1 , c},{r , c + 1 },{r + 1 , c} ,{r , c - 1}};
        
        for(int[] neigh : neighbours){
            int nr = neigh[0];
            int nc = neigh[1];
            
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]){
                str.append(mat[nr][nc]);
                visited[nr][nc] = true;
                search(nr , nc , mat , visited , str , word);
                visited[nr][nc] = false;
                str.deleteCharAt(str.length() - 1);
            }
        }
        
    }
    public boolean isWordExist(char[][] mat, String word) {
        // Code here
        List<int[]> startingIndices = new ArrayList<>();
        m = mat.length;
        n = mat[0].length;
        found = false;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == word.charAt(0)){
                    startingIndices.add(new int[]{i , j});
                }
            }
        }
        StringBuilder str = new StringBuilder("");
        
        for(int i = 0 ; i < startingIndices.size() ; i++){
            
            boolean[][] visited = new boolean[m][n];
            
            int row = startingIndices.get(i)[0];
            int col = startingIndices.get(i)[1];
            visited[row][col] = true;
            str.append(mat[row][col]);
            
            search(row , col , mat , visited , str , word);
            
            if(found){
                return true;
            }
            str = new StringBuilder("");
        }
        
        return false;
    }
}

