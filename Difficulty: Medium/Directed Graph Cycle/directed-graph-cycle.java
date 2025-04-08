//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        while (tc-- > 0) {
            int V = sc.nextInt();
            int E = sc.nextInt();
            int[][] edges = new int[E][2];
            for (int i = 0; i < E; i++) {
                edges[i][0] = sc.nextInt();
                edges[i][1] = sc.nextInt();
            }

            Solution obj = new Solution();
            boolean ans = obj.isCyclic(V, edges);
            System.out.println(ans ? "true" : "false");
        }
        sc.close();
    }
}
// } Driver Code Ends

class Solution {
     public static boolean isCycle(ArrayList<ArrayList<Integer>> adj, int crr, boolean[] vis, boolean[] recStack) {
        vis[crr] = true;
        recStack[crr] = true;

        for (int neighbor : adj.get(crr)) {
            if (recStack[neighbor]) {
                return true;
            } else if (!vis[neighbor]) {
                if (isCycle(adj, neighbor, vis, recStack)) {
                    return true;
                }
            }
        }

        recStack[crr] = false;
        return false;
    }

    public boolean isCyclic(int V, int[][] edges) {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]); 
        }

        boolean[] vis = new boolean[V];
        boolean[] recStack = new boolean[V];

        for (int j = 0; j < V; j++) {
            if (!vis[j]) {
                if (isCycle(adj, j, vis, recStack)) {
                    return true;
                }
            }
        }

        return false;
    }
}