class Solution {
  public:
    virtual int maxKadan(vector<int> &arr){
      int maxv=INT_MIN, c=0;
      for(int &x: arr){
        c += x;
        maxv = max(maxv, c);
        if(c<0) c=0;
      }
      return maxv;
    } 
    
    virtual int minKadan(vector<int> &arr){
      int minv=INT_MAX, c=0;
      for(int &x: arr){
        c += x;
        minv = min(minv, c);
        if(c>0) c=0;
      }
      return minv;
    }
  
    virtual int maxCircularSum(vector<int> &arr){
      int ts=0;
      for(int &x: arr) ts+=x;
      
      int op1 = maxKadan(arr);
      int op2 = ts-minKadan(arr);
      int op2r = (op2==0)? INT_MIN: op2;
      return max(op1, op2r);
    }
};