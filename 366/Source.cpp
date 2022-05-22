#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	if (n % 3 == 0) {
		cout << 2;
		return 0;
	}
	cout << 1;
}