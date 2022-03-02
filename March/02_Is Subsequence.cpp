class Solution {
public:
    bool isSubsequence(string s, string t) {
      int sIndex = 0 , tIndex = 0 ;
        
        while(tIndex < t.size()){
            if(s[sIndex] == t[tIndex]){
                sIndex++,tIndex++;
            }else{
                tIndex++;
            }
        }
        
        return s.size() == sIndex;
    }
};