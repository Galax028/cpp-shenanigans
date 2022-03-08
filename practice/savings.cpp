// https://atcoder.jp/contests/abc206/tasks/abc206_b

#include <iostream>

using std::cin, std::cout;

int main() {
    int n, m = 0;
    cin >> n;
    for (int i = 1; i < 1e9; i++) {
	m += i;
	if (m >= n) {
	    cout << i << "\n";
	    break;
	}
    }
    return 0;
}
