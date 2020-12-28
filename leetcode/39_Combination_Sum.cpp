class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        combinationSum(candidates, target, curr, res, 0);
        return res;
    }
    
    void combinationSum(vector<int>& candidates, int target, vector<int>& curr, vector<vector<int>>& res, int i) {
        if (i == candidates.size()) {
            if (target == 0) {
                res.push_back(vector<int>(curr));
                return;
            } else {
                return;
            }
        }
        if (target == 0) {
            res.push_back(vector<int>(curr));
            return;
        } else if (target < 0) {
            return;
        }
        int candidate = candidates[i];
        for (int amount = 0; amount*candidate <= target; amount++) {
            for (int i = 0; i < amount; i++) {
                curr.push_back(candidate);
            }
            combinationSum(candidates, target-amount*candidate, curr, res, i+1);
            for (int i = 0; i < amount; i++) {
                curr.pop_back();
            }
        }
    }
};