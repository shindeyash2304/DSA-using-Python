class Solution {
    minWindow(s, p) {
        // code here
        let freq = new Map();
        [...p].forEach((elem)=>{
            if(freq.has(elem)){
                freq.set(elem,freq.get(elem)+1);
            }else{
                freq.set(elem,1);
            }
        });
        let n = s.length;
        let start =0;
        let end =0;
        let startInd =-1;
        let minLen = Number.MAX_VALUE;
        let uniqueCharCount = freq.size;
        while(end<n){
            //expansion
            let ch = s[end];
            if(freq.has(ch)){
                freq.set(ch,freq.get(ch)-1);
                if(freq.get(ch)===0) {
                    uniqueCharCount--;
                }
            }
            while(uniqueCharCount===0){
                //perfect match,calculate minLen and startIndex
                let len = end-start+1;
                if(len<minLen){
                    minLen=len;
                    startInd=start;
                }
                //shrinking
                ch = s[start];
                if(freq.has(ch)){
                    freq.set(ch,freq.get(ch)+1);
                    if(freq.get(ch)>0){
                        uniqueCharCount++;
                    }
                }
                start++;
            }
            end++;
        }
        return startInd === -1 ? "" : s.substring(startInd,startInd+minLen);
    }
}