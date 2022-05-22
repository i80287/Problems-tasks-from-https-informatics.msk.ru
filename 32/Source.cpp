#include <iostream>
#include <vector>
using namespace std;
int f(vector<int>& cns, vector<vector <int>>& a, int m, int i) {
	if () {
		if
	}
	else {
		int temp1 = f(cns, a, m - cns[i], i - 1);
		int temp2 = f(cns, a, m, i - 1);
		if (temp1 == -1 || temp2 == -1) {
			if (temp1 == -1) {
				if (temp2 == -1) {
					return -1;
				}
				return temp2;
			}
			if (temp2 == -1) {
				return -1;
			}
			return temp1;
		}
		else {
			if (temp1 < temp2) {
				cout << cns[i] << " ";
				return temp1;
			}
			return temp2;
		}
	}
}
int main() {
	int m, n;
	cin >> m >> n;
	int sum = 0;
	vector <int> cns(2 * n);
	for (int i = 0; i < 2 * n; i += 2) {
		cin >> cns[i];
		cns[i + 1] = cns[i];
		sum += cns[i];
	}
	if (sum < 2 * m) {
		cout << -1;
		return 0;
	}
	vector <vector <int>> dp(m, vector(2 * n));
	for (int i = 0; i < 2 * n; i++) {
		dp[0][i] = 0;
	}
	f(dp, a, m, 2 * n - 1);
}
