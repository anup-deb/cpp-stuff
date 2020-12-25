class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return vector<int>{};
        }
        int N = matrix.size();
        int M = matrix[0].size();
        int num_diagonals = N+M-1;
        vector<int> res;
        for (int i = 0; i < num_diagonals; i++) {
            int start_row = (i < M) ? 0 : i-M+1;
            int start_col = (i < M) ? i : M-1;
            
            vector<int> diag;
            iterateDiagonal(matrix, diag, false, start_row, start_col);
            if (i % 2 == 0) {
                // flip diag
                reverse(diag.begin(), diag.end());
            }
            res.insert(res.end(), diag.begin(), diag.end());
        }
        return res;
    }
    
    void iterateDiagonal(vector<vector<int>>& matrix, vector<int>& res, bool is_upward, int i, int j) {
        int row = i;
        int col = j;
        int size = matrix[0].size();
        while(row >= 0 && row < matrix.size() && col >= 0 && col < size) {
            res.push_back(matrix[row][col]);
            if (is_upward) {
                row--;
                col++;
            } else {
                row++;
                col--;
            }
        }
    }
};