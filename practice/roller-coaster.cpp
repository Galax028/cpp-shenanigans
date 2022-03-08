// https://atcoder.jp/contests/abc142/tasks/abc142_b

#include <iostream>

using std::cin, std::cout;

int main() {
    int n, k, h[100005];
    int r = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
	cin >> h[i];
    }
    for (int j = 0; j < n; j++) {
	if (h[j] >= k) r++;
    }
    cout << r << "\n";
    return 0;
}
