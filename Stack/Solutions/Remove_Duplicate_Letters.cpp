class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char>st;
        vector<int>last(26,0);   
        vector<bool>seen(26,0);
        int n = s.size();
        for(int i=0;i<n;i++){
            last[s[i]-'a']=i;
        }
        for(int i=0;i<n;i++){
            if(seen[s[i]-'a'])continue;
            while(!st.empty()&&st.top()>s[i]&&last[st.top()-'a']>i){
                seen[st.top()-'a']=false;
                st.pop();
            }
            st.push(s[i]);
            seen[s[i]-'a']=true;
        }
        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};
