class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string cur;
        for (char c : path) {
            if (c == '/') {
                if (cur == "..") {
                    if (!st.empty()) st.pop_back();
                } 
                else if (cur != "" && cur != ".") {
                    st.push_back(cur);
                }
                cur = "";
            } else {
                cur += c;
            }
        }
        if (cur == "..") {
            if (!st.empty()) st.pop_back();
        } 
        else if (cur != "" && cur != ".") {
            st.push_back(cur);
        }
        string ans;
        for (auto &s : st) ans += "/" + s;
        return ans.empty() ? "/" : ans;
    }
};
