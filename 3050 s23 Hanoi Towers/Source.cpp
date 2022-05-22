#include <iostream>
using namespace std;
void dasfunkt(int n, int a, int b) {
	if (n == 1) {
		cout << n << " " << a << " " << b << endl;
	}
	else {
		dasfunkt(n - 1, a, 6 - a - b);
		cout << n << " " << a << " " << b << endl;
		dasfunkt(n - 1, 6 - a - b, b);
	}
}
int main() {
	int n;
	cin >> n;
	dasfunkt(n, 1, 3);
}