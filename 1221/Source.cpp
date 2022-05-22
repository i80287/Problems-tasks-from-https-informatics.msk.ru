#include <iostream>
#include <vector>
using namespace std;
int main() {
	int m, n, k;
	cin >> m >> n >> k;
	vector <vector <int>> tb(m + 2, vector <int> (n + 2, 0));
	int i, j, p = 0;
	for (int kk = 0; kk < k; ++kk) {
		cin >> i >> j;
		tb[i][j] = 1;
	}

	/*for (int i = 0; i < m + 2; ++i) {
		for (int j = 0; j < n + 2; ++j) {
			cout << tb[i][j] << " ";
		}
		cout << endl;
	}*/
	for (int i = 1; i < m + 1; ++i) {
		for (int j = 1; j < n + 1; ++j) {
			if (tb[i][j] == 1) {
				if (tb[i + 1][j] == 0) p++;
				if (tb[i][j + 1] == 0) p++;
				if (tb[i][j - 1] == 0) p++;
				if (tb[i - 1][j] == 0) p++;
			}
		}
	}
	cout << p;
}