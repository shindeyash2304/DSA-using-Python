class Solution {
    public ArrayList<Integer> findGreater(int[] arr) {
        HashMap<Integer, Integer> freq = new HashMap<>();
        for (int num : arr) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }

        Stack<Integer> st = new Stack<>();
        ArrayList<Integer> ans = new ArrayList<>();

        for (int i = arr.length - 1; i >= 0; i--) {
            int num = arr[i];

            while (!st.isEmpty() && freq.get(st.peek()) <= freq.get(num)) {
                st.pop();
            }

            if (st.isEmpty()) {
                ans.add(-1);
            } else {
                ans.add(st.peek());
            }

            st.push(num); 
        }

        Collections.reverse(ans); 
        return ans;
    }
}