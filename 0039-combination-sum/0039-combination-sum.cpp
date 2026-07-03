class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }

private:
    void backtrack(const vector<int>& candidates, int remaining, int start, vector<int>& current, vector<vector<int>>& result) {
        if (remaining == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > remaining) {
                continue;
            }
            current.push_back(candidates[i]);
            backtrack(candidates, remaining - candidates[i], i, current, result);
            current.pop_back();
        }
    }
};