#include <iostream>
#include <vector>
using namespace std;
int main() {
	int a, n, k;
	cin >> k;
	vector <int> swt;
	for (int i = 0; i < 2 * k; i += 2) {
		cin >> a >> n;
		for (int j = 0; j < n; ++j) {
			swt.push_back(a);
		}
	}
	n = swt.size();
	int i = 0, j = n - 1;
	while (j - i > 1 && i < n - 1 && j > 0) {
		if (swt[i] > swt[j]) {
			swt[i + 1] += swt[j];
			swt[j - 1] += swt[j];
			swt[i] -= swt[j];
			j--;
			if (swt[i] == 0) i++;
		}
		else {
			swt[i + 1] += swt[i];
			swt[j - 1] += swt[i];
			swt[j] -= swt[i];
			i++;
			if (swt[j] == 0) j--;
		}
	}
	if (i == j) {
		cout << 1 << endl << swt[i];
	}
	else {
		cout << 2 << endl << swt[i] << " " << swt[j];
	}

}