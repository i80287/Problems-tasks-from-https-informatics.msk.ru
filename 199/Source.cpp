#include <iostream>
using namespace std;
int funkt(int a, int b) {
	if (b == 0) return a;
	return funkt(b, a % b);
}
int main() {
	int a, b;
	cin >> a >> b;
	cout << funkt(a, b);
}
