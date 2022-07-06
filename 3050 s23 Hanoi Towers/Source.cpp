#include <iostream>
using namespace std;
void f(int n, int a, int b) {
	if (n == 1) {
		cout << n << " " << a << " " << b << endl;
	}
	else {
		f(n - 1, a, 6 - a - b);
		cout << n << " " << a << " " << b << endl;
		f(n - 1, 6 - a - b, b);
	}
}
int main() {
	int n;
	cin >> n;
	f(n, 1, 3);
}