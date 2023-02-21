
//https://codeforces.com/contest/862/problem/E

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Calculate the prefix XORs of the array
    vector<int> prefix_xor(n+1);
    for (int i = 1; i <= n; i++) {
        prefix_xor[i] = prefix_xor[i-1] ^ a[i-1];
    }

    // Process each query
    while (q--) {
        int l, r;
        cin >> l >> r;

        int xor_sum = prefix_xor[r] ^ prefix_xor[l-1];
        int count = r - l + 1;

        // If the number of elements is odd, the answer is odd
        if (count % 2 == 1) {
            cout << "1\n";
        } else {
            // If the XOR sum is odd, the answer is odd
            if (xor_sum % 2 == 1) {
                cout << "1\n";
            } else {
                // Otherwise, the answer is even
                cout << "0\n";
            }
        }
    }

    return 0;
}
