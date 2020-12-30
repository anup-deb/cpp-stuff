class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (const auto& i : nums) {
            s.insert(i);
        }
        
        int max_length = 0;
        int curr_int;
        for (auto& i : s) {
            curr_int = i;
            if (s.find(curr_int-1) == s.end()) {
                // start of sequence
                int length = 1;
                while(s.find(++curr_int) != s.end()) {
                    ++length;
                }
                max_length = max(max_length, length);
            }
        }
        return max_length;
    }
};