#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector <vector <int>> dp(n + 1, vector <int>(360));
	dp[0][0] = 1;
	for (int j = 1; j < 360; ++j) {
		dp[0][j] = 0;
	}
	for (int i = 1; i < n + 1; ++i) {
		for (int j = 0; j < 360; ++j) {
			int temp = j;
			while (temp - a[i - 1] < 0) {
				temp += 360;
			}
			dp[i][j] = max(dp[i - 1][(temp - a[i - 1]) % 360], dp[i - 1][(temp + a[i - 1]) % 360]);
		}
	}
	cout << dp[n][0] << endl;








	/*
	int s, n;
	cin >> s >> n;
	vector <int> bars(n);
	vector <int> dp(s + 1, 0);
	for (int i = 0; i < n; ++i) {
		cin >> bars[i];
	}
	dp[0] = 1;
	for (int j = 0; j < n; ++j) {
		int elem = bars[j];
		vector <int> dp_n(s + 1, 0);
		for (int i = 1; i < s + 1; ++i) {
			if (i - elem >= 0) {
				if (dp[i - elem] || dp[i]) {
					dp_n[i] = 1;
				}
			}
		}
		for (int i = 1; i < s + 1; i++) {
			if(dp_n[i]) dp[i] = dp_n[i];
			dp_n[i] = 0;
		}
	}
	for (int i = 0; i < s + 1; ++i) {
		cout << i << " " << dp[i] << endl;
	}*/
	
}