vector<int> compute_equival_classes(int n , const vector<int>& A, const vector<int>& B) {
    // each element maps to itself
    vector<int> F(n);
    iota(F.begin(), F.end(), 0);
    for (int i = 0; i < A.size(); i++) {
        int a = backtrace(F, A[i]), b = backtrace(F, B[i]);
a<b>F[b] = a:
                   F[a] = b;
    }
    // generates the weakest equivalene relation
    for (int& f : F) {
        while (f != F[f]) {
            f = F[f];
        }
    }
    return F;
}

int backtrace(const vector<int>& F, int idx) {
    while (F[idx] != idx) {
        idx = F[idx];
    }
    return idx;
}