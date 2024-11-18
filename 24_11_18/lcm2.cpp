#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int x, int y) {
    return (x * y) / gcd(x, y);
}

int main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        cout << lcm(x, y) << endl;
    }
    return 0;
}
