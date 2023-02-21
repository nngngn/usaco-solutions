
// trapped in the haybales

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> positions(n);
    vector<int> sizes(n);

    for (int i = 0; i < n; i++) {
        cin >> sizes[i] >> positions[i];
    }

    int ans = 0;

    // Sort haybales by position
    sort(positions.begin(), positions.end());

    // Try each gap between adjacent haybales
    for (int i = 0; i < n-1; i++) {
        int left_size = sizes[i], right_size = sizes[i+1];
        int left_pos = positions[i], right_pos = positions[i+1];
        int gap = left_pos + left_size - right_pos;

        // Binary search for a haybale that can block the gap
        int lo = i, hi = n-1, j = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (positions[mid] - right_pos >= gap) {
                j = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        // If there is a haybale that can block the gap, update the answer
        if (j != -1 && positions[j] - right_pos == gap && sizes[j] > right_size) {
            ans += sizes[i];
            sizes[j] += sizes[i];
        }
    }

    cout << ans << endl;

    return 0;
}
