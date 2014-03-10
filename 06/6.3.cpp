int minBattery(vector<int> heights) {
    int min_height = INT_MAX, capacity = 0;
    for (const int height : heights) {
        capacity = max(capacity, height - min_height);
        min_height = min(height , min_height);
    }
    return capacity;
}