class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s+=s;
        int d1=0,d2=0,ans=INT_MAX;
        for(int i=0;i<(2*n);i++){
            if(s[i]!=(i%2?'1':'0'))d1++;
            if(s[i]!=(i%2?'0':'1'))d2++;
            if(i>=n){
               if(s[i-n]!=((i-n)%2?'1':'0'))d1--;
               if(s[i-n]!=((i-n)%2?'0':'1'))d2--;
            }
            if(i>=n-1){
                ans=min(ans,min(d1,d2));
            }
        }
        return ans;
    }
};
