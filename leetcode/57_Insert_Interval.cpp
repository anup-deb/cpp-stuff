class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) {
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<vector<int>> ans{};
        int i = 0;
        
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }
        if (i == intervals.size()) {
            ans.push_back(newInterval);
            return ans;
        }
        int start;
        if (intervals[i][0] > newInterval[1]) {
            ans.push_back(newInterval);
            start = intervals[i][0];
        } else {
            start = min(intervals[i][0], newInterval[0]);    
        }
        
        int end = max(intervals[i][1], newInterval[1]);
        vector<int> new_interval{start, end};
        while (i < intervals.size() && new_interval[1] >= intervals[i][0]) {
            new_interval[1] = max(new_interval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(new_interval);
        while (i < intervals.size()) {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};