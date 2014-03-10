void quicksort(int[] A, int int pivot_index) {
    int pivot = A[pivot_index];
    int smaller = 0, equal = 0, larger = sizeof(A) / sizeof(*A) - 1;
    while (equal <= larger) {
        if (A[equal] < pivot) {
            swap(A[smaller++], A[equal++]);
        } else if (A[equal] == pivot) {
            equal++;
        } else {
            swap(A[equal], A[larger--]);
        }
    }
}