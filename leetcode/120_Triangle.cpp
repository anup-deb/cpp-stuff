class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0 || triangle[0].size() == 0) {
            return 0;
        }
        unordered_map<string, int> dp;
        return minimumTotal(triangle, 0, 0, dp);
    }
    
    int minimumTotal(vector<vector<int>>& triangle, int row, int col, unordered_map<string, int>& dp) {
        if (row >= triangle.size()) {
            return 0;
        }
        int row_size = triangle[row].size();
        if (col >= row_size || col < 0) {
            return INT_MAX; 
        }
        string key = to_string(row) + "#" + to_string(col);
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }
        int res = min(minimumTotal(triangle, row+1, col, dp), minimumTotal(triangle, row+1, col+1, dp)) + triangle[row][col];
        
        dp[key] = res;
        return res;
    }
};