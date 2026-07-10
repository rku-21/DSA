class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();

        bool fm = (!s.empty() && (s[0] == p[0] || p[0] == '.'));

        if (p.size() >= 2 && p[1] == '*') {
            return isMatch(s, p.substr(2)) || (fm && isMatch(s.substr(1), p));
        } else {
            return fm && isMatch(s.substr(1), p.substr(1));
        }
    }
};
