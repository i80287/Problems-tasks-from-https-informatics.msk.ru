#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, min = 101;
	cin >> n;
	if (n == 100) {
		cout << 1;
		return 0;
	}
	for (int a2 = 0; a2 <= 1; a2++) {
		for (int a3 = 0; a3 <= 1; a3++) {
			for (int a4 = 0; a4 <= 2; a4++) {
				for (int a5 = 0; a5 <= 2; a5++) {
					for (int a6 = 0; a6 <= 4; a6++) {
						for (int a7 = 0; a7 <= 6; a7++) {
							for (int a8 = 0; a8 <= 11; a8++) {
								for (int a9 = 0; a9 <= 25; a9++) {
									for (int a10 = 0; a10 <= 100; a10++) {
										if ((81 * a2 + 64 * a3 + 49 * a4 + 36 * a5 + 25 * a6 + 16 * a7 + 9 * a8 + 4 * a9 + a10) == n) {
											if ((a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10) < min) {
												min = a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << min;
}