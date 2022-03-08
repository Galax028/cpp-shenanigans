// https://atcoder.jp/contests/abc235/tasks/abc235_a

#include <iostream>

using std::cin, std::cout;

int main() {
    int x, a, b, c;
    cin >> x;
    c = x%10;
    b = (x/10)%10;
    a = x/100;
    cout << (a*100) + (a*10) + a + (b*100) + (b*10) + b + (c*100) + (c*10) + c << "\n";
    return 0;
}
