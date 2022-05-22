#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, m, l, r, gg, aa;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int j = 0; j < m; j++) {
        char com;
        cin >> com;
        if (com == 'g') {
            cin >> gg;
            gg--;
            cout << a[gg] << " ";
        }else if(com == 'a'){
            cin >> l >> r >> aa;
            l--;
            r--;
            for (int i = l; i <= r; i++) {
                a[i] = aa;
            }
        }
    }
}