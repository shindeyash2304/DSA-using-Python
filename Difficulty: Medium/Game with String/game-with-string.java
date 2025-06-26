class Solution {
    public int minValue(String s, int k) {
        int n=s.length();
        int freq[]=new int[26];
        
        for(int i=0;i<n;i++){
                char ch=s.charAt(i);
                freq[ch-'a']++;
        }
        
        PriorityQueue<Integer> pq=new PriorityQueue<>(Collections.reverseOrder());
        for(int a: freq) {
        	if(a!=0)pq.add(a);
        }
        
        
        while(k>0) {
        	if(pq.size()>0) {
            	int temp=pq.poll();            	
            	if(temp>0) {
            		pq.add(temp-1);        		
            	}
        	}
        	k--;
        }
       
        int ans=0;
        for(int a: pq) {
        	a=a*a;
        	ans+=a;
        }
        return ans;
        
    }
}