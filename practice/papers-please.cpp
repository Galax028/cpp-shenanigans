// https://atcoder.jp/contests/abc155/tasks/abc155_b

#include <iostream>

using std::cin, std::cout;

int main() {
    int n, a[100005];
    cin >> n;
    for (int i = 0; i < n; i++) {
	cin >> a[i];
    }
    for (int j = 0; j < n; j++) {
	if (a[j] % 2 == 0) {
	    if (a[j] % 3 == 0 || a[j] % 5 == 0) continue;
	    else {
                cout << "DENIED\n";
	        return 0;
	    }
	}
    }
    cout << "APPROVED\n";
    return 0;
}
