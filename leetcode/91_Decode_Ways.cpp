class Solution {
public:
    int numDecodings(string s) {
        unordered_map<int, int> m;
        return numDecodings(s, 0, m);
    }
    
    
    int numDecodings(string s, int i, unordered_map<int, int>& map) {
        if (i == s.size()) {
            return 1;
        } else if (i > s.size()) {
            return 0;
        }
        if (map.find(i) != map.end()) {
            return map[i];
        }
        int num_first = stoi(s.substr(i, 1));
        int num_second = 0;
        if (i <= s.size()-2) {
            num_second = stoi(s.substr(i, 2));
        }
        int num_ways = 0;
        if (num_first >= 1 && num_first <= 26) {
            num_ways += numDecodings(s, i+1, map);
        }
        
        if (num_first != 0 && num_second >= 1 && num_second <= 26 && i <= s.size()-2) {
            num_ways += numDecodings(s, i+2, map);
        }
        map[i] = num_ways;
        return num_ways; 
    }
};