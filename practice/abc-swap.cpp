// https://atcoder.jp/contests/abc161/tasks/abc161_a
#include <iostream>

using std::cin, std::cout;

int main() {
    int x, y, z;
    int a, b, c;
    cin >> x >> y >> z;
    a = y;
    b = x;
    c = a;
    a = z;
    cout << a << " " << b << " " << c << "\n";
    return 0;
}
