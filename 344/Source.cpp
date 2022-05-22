#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, ans = 0, cn = 0;
	cin >> n;
	while (n) {
		ans += (n % 10) * pow(2, cn);
		cn++;
		n /= 10;
	}
	cout << ans;
}