class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return vector<string>{""};
        }
        if (n == 1) {
            return vector<string>{"()"};
        }
        vector<string> prev = generateParenthesis(n-1);
        vector<string> res;
        for (auto const& s : prev) {
            for (int i = 0; i < s.size(); i++) {
                res.push_back(s.substr(0, i) + "()" + s.substr(i));
            }
        }
        unordered_set<string> s(res.begin(), res.end());
        res.assign(s.begin(), s.end());
        return res;
    }
};