
//http://www.usaco.org/index.php?page=viewproblem2&cpid=990

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }

    // find the position of the first cow that is out of order
    int i = n - 1;
    while (i > 0 && cows[i] > cows[i-1]) {
        i--;
    }

    // output the index of the new position of the cow
    cout << i << endl;

    return 0;
}
