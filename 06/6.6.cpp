pair<int, int> find_longest_increasing_subarray(const vector<int>& A) {
    int max_len = 1;
    pair<int, int> ans(0, 0);
    int i = 0;
    while (i < A.size()) {
        // check backwardly and skip if A[j] >=A[j+1]
        bool is_skipable = false;
        for (int j = i + max_len - 1; j >= i; j--) {
            if (j + 1 >= A.size() || A[j] >= A[j + 1]) {
                i = j + 1;
                is_skippalbe = true;
                break;
            }
        }

        // check forwardly if it is not skippable
        if (is_skippable == false) {
            i += max_len - 1;
            while (i + 1 < A.size() && A[i] < A[i + 1]) {
                i++;
                max_len++;
            }
            ans = {i - max_len + 1, i};
        }
    }
    return ans;
}