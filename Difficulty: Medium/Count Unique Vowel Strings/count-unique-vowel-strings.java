class Solution {
    
    static int fact(int n)
    {
        if(n<=1)return 1;
        else return n*fact(n-1);
    }
    
    public int vowelCount(String s) {
        // code here
        Map<Character,Integer>map=new HashMap();
        
        
        for(char c:s.toCharArray())
        {
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            {
                map.put(c,map.getOrDefault(c,0)+1);
            }
        }
        
        int unique=map.size();
        if(unique==0)return 0;
        int res=fact(unique);
        
        for(Map.Entry<Character,Integer>entry:map.entrySet())
        {
            char key=entry.getKey();
            int val=entry.getValue();
            res*=val;
        }
        return res;
    }
}