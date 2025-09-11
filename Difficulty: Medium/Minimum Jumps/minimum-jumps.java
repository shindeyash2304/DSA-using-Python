class Solution {
    static int minJumps(int[] arr) {
        int jump = 0;
        int currEnd = 0; // Current range of jump
        int maxRec = 0; // Farthest point we can reach

        int n = arr.length;
        for(int i = 0; i < n - 1; i ++) {
            // Update the farthest/maxRec  we can reach
            maxRec = Math.max(maxRec, i + arr[i]);
            // If we have reached the end of the current jump range
            if(i == currEnd) {
                jump ++;
                currEnd = maxRec;
                // Optional // If currentEnd is already at or beyond the last index, we are done
                // if(currEnd >= n - 1) { // bcz last element par to reach hi karan hai isliye usko need nhi hai
                //     break;
                // }
                 // optional // If we can't move forward anymore, stuck
                // if(currEnd == i) { // 2, 1, 0, 3, 4 --> dry run  the you will understand
                //     return -1;
                // }
            }
            
        }
        return currEnd >= n - 1 ? jump : -1;
    }
}