#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);   // Base index
        
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();

                if (st.empty()) {
                    st.push(i);   // New base
                } else {
                    ans = max(ans, i - st.top());
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    cout << obj.longestValidParentheses("(()") << endl;      // 2
    cout << obj.longestValidParentheses(")()())") << endl;   // 4
    cout << obj.longestValidParentheses("") << endl;         // 0

    return 0;
}
