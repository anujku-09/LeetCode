class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        for(char d : num){
            while(!st.empty() && k > 0 && st.back() > d){
                st.pop_back();
                k--;
            }
            st.push_back(d);
        }
        while(k > 0){
            st.pop_back();
            k--;
        }
        int i = 0;
        while(i < st.size() && st[i] == '0'){
            i++;
        }
        string res = st.substr(i);
        return res.empty() ? "0" : res;
    }
};