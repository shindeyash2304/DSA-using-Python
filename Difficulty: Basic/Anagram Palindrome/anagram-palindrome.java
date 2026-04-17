class Solution {
    boolean canFormPalindrome(String s) {
        HashMap<Character,Integer> hm = new HashMap<>();
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            hm.put(ch,hm.getOrDefault(ch,0)+1);
        }
        boolean oneSingleChar = false;
        for(char ch : hm.keySet()){
            if(hm.get(ch)%2 ==1){
                if(oneSingleChar) return false;
                else oneSingleChar = true;
            }else if(hm.get(ch)%2 ==0){
               continue;
            }
        }
        return true;
    }
}