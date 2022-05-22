#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void t_cr(vector <int>& a, vector <int>& t_s, int i, int tl, int tr) {
    if (tl == tr) {
        if (a[tl] == 0) {
            t_s[i] = 1;
        }
        else {
            t_s[i] = 0;
        }
    }
    else {
        int temp = (tr + tl) / 2;
        t_cr(a, t_s, 2 * i, tl, temp);
        t_cr(a, t_s, 2 * i + 1, temp + 1, tr);
        t_s[i] = t_s[2 * i] + t_s[2 * i + 1];
    }
}
int s0(vector <int>& t_s, int i, int tl, int tr, int l, int r) {
    //cout<<"     "<<tl<<" "<<tr<<" "<<l<<" "<<r<<" "<<i<<" "<<t[i]<<" "<< t_amnt[i] << " " << amount << endl;
    if (l > r) {
        return 0;
    }
    //cout << "     " << i << " " << amount << endl;
    if (l == tl && r == tr) {
        return t_s[i];
    }
    int temp = (tl + tr) / 2;
    return s0(t_s, 2 * i, tl, temp, l, min(r, temp)) + s0(t_s, 2 * i + 1, temp + 1, tr, max(l, temp + 1), r);
}

void upd(vector <int>& t_s, int i, int tl, int tr, int u_i, int u) {
    if (tl == tr) {
        if (u == 0) {
            t_s[i] = 1;
        }
        else {
            t_s[i] = 0;
        }

    }else {
        int temp = (tr + tl) / 2;
        if (u_i > temp) {
            upd(t_s, 2 * i + 1, temp + 1, tr, u_i, u);

        }else{
            upd(t_s, 2 * i, tl, temp, u_i, u);
        }
        t_s[i] = t_s[2 * i] + t_s[2 * i + 1];
    }
}
int main()
{
    int n, m, l, r, u, u_i;
    cin >> n;
    vector <int> a(n);
    vector <int> t_s(4 * n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    t_cr(a, t_s, 1, 0, n - 1);
    /*for (int j = 0; j<4 * n; j++) {
        cout<<t[j]<<" "<<t_amnt[j]<<endl;
    }*/
    cin >> m;
    for (int j = 0; j < m; j++) {
        char com;
        cin >> com;
        if (com == 'u') {
            cin >> u_i >> u;
            u_i--;
            upd(t_s, 1, 0, n-1, u_i, u);
            a[u_i] = u;
        }else if(com == 's'){
            cin >> l >> r;
            l--;
            r--;
            cout << s0(t_s, 1, 0, n - 1, l, r)<<" ";
        }
        else if (com == 'm') {
            for (int k = 0; k < n; k++) {
                cout << a[k] << " ";
            }
            cout << endl;
        }
    }
}