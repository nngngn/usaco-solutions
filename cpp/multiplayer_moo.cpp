
// multiplayer moo
// http://www.usaco.org/index.php?page=viewproblem2&cpid=836

#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;

    // Compute the number of numbers divisible by 3, 5, and 15
    ll div3 = n / 3;
    ll div5 = n / 5;
    ll div15 = n / 15;

    // Compute the number of numbers NOT divisible by 3 or 5
    ll notDiv3Or5 = n - div3 - div5 + div15;

    // Compute the value of the nth mooBuzz number
    ll ans = (n - notDiv3Or5 - 1) * 15;
    while (ans % 3 == 0 || ans % 5 == 0) {
        ans += 15;
    }

    cout << ans << endl;

    return 0;
}



 // count numbers divisible by 3, 5, 15
 // then subtract the ones not divisible by 3 or 5  
