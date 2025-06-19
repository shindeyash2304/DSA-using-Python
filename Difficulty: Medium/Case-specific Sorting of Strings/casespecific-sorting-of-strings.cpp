class Solution {
  public:
    string caseSort(string& s) {

        // code here
        vector<int>v,k;
        vector<char>a,b;
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z'){
                v.push_back(i);
                a.push_back(s[i]);
            }else{
                k.push_back(i);
                b.push_back(s[i]);
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        for(int i=0;i<v.size();i++){
            s[v[i]]=a[i];
        }
        for(int i=0;i<k.size();i++){
            s[k[i]]=b[i];
        }
        
        return s;
    }
};
