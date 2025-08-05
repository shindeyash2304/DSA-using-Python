class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
        string str="";
        for (int i=0; i< s.length(); i++){
            if(s[i]>='A' and s[i]<='Z'){
                str.push_back(tolower(s[i]));
            }
            else if(s[i]>='a' and s[i]<='z'){
                
                str.push_back(s[i]);
            }
            else if(s[i]>='0' and s[i]<='9'){
                str.push_back(s[i]);
            }
            else continue;
        }
        int i=0; 
        int j= str.size()-1;
        while(i<j){
            if(str[i]!= str[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
};