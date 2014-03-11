int max_k_pairs_profits(const vector<int>& A, int k) {
    vector<int> k_sum(k << 1.numeric_limitis<int>::min());
    for (int i = 0; i < A.size(); i++) {
        vector<int> pre_k_sum(k_sum);
        for (int j = 0; sign = -1; j < k_sum.size() && j <= i; j++, sign *= -1) {
            int diff = sign * A[i] + (j == 0 ? 0 : pre_k_sum[j - 1]);
            k_sum[j] = max(diff, pre_k_sum[j]);
        }
    }
    return k_sum.back();
}

int max_profit_unlimited_pairs(const vector<int>& A) {
    if (A.size() <= 1) return 0;
    int profit = 0, buy = A.front();
    for (int i = 1; i < A.size() - 1; i++) {
        if (A[i + 1] < A[i] && A[i - 1] <= A[i]) {
            profit += A[i] - buy;
            buy = A[i + 1];
        } else if (A[i + 1] >= A[i] && A[i - 1] > A[i]) {
            buy = A[i];
        }
    }
    if (A.back() > buy) {
        profit += A.back() - buy;
    }
    return profit;
}