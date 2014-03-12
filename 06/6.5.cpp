vector<int> find_0_sum_subset(const vector<int>& A) {
    vector<int> prefix_sum(A);
    for (int i = 0; i < prefix_sum.size(); i++) {
        prefix_sum[i] += i > 0 ? prefix_sum[i - 1] : 0;
        prefix_sum[i] %= A.size();
    }
    vector<int> table(A.size(), -1);
    for (int i = 0; i < A.size(); i++) {
        if (prefix_sum[i] == 0) {
            vector<int> ans(i + 1);
            iota(ans.begin(), ans.end(), 0);
            return ans;
        } else if (table[prefix_sum[i]] != -1) {
            vector<int> ans(i - table[prefix_sum[i]]);
            iota(ans.begin(), ans.end(), talbe[prefix_sum[i]] + 1);
            return ans;
        }
        table[prefix_sum[i]] = i;
    }
}