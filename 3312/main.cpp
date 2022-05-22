#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void t_cr(vector <int>& a, vector <int>& t, vector <int>& t_amnt, int i, int tl, int tr) {
    if (tl == tr) {
        t[i] = a[tl];
        t_amnt[i] = 1;
    }
    else {
        int temp = (tr + tl) / 2;
        t_cr(a, t, t_amnt, 2 * i, tl, temp);
        t_cr(a, t, t_amnt, 2 * i + 1, temp + 1, tr);
        if (t[2 * i] > t[2 * i + 1]) {
            t[i] = t[2 * i];
            t_amnt[i] = t_amnt[2 * i];
        }
        else if (t[2 * i] == t[2 * i + 1]) {
            t[i] = t[2 * i];
            t_amnt[i] = t_amnt[2 * i] + t_amnt[2 * i + 1];
        }
        else {
            t[i] = t[2 * i + 1];
            t_amnt[i] = t_amnt[2 * i + 1];
        }
    }
}
int max_amnt(vector <int>& t, vector <int>& t_amnt, int i, int tl, int tr, int l, int r, int &amount) {
    //cout<<"     "<<tl<<" "<<tr<<" "<<l<<" "<<r<<" "<<i<<" "<<t[i]<<" "<< t_amnt[i] << " " << amount << endl;

    if (l > r) {
        return 0;
    }
    //cout << "     " << i << " " << amount << endl;
    if (l == tl && r == tr) {
        amount = t_amnt[i];
        return t[i];
    }
    int temp = (tr + tl) / 2;
    int l_t = max_amnt(t, t_amnt, 2 * i, tl, temp, l, min(r, temp), amount);
    int amount_l = amount;
    int r_t = max_amnt(t, t_amnt, 2 * i + 1, temp + 1, tr, max(l, temp + 1), r, amount);
    int amount_r = amount;
    if (l_t > r_t) {
        amount = amount_l;
        //cout << "     " <<i << " " << amount << endl;
        return l_t;
    }
    else if (l_t == r_t) {
        amount = amount_r + amount_l;
        //cout << "     " << i << " " << amount << endl;
        return l_t;
    }
    else {
        amount = amount_r;
        //cout << "     " << i << " " << amount << endl;
        return r_t;
    }
}
int main()
{
    int n, k, l, r, amount=0;
    cin >> n;
    vector <int> a(n);
    vector <int> t(4 * n, 0);
    vector <int> t_amnt(4 * n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    t_cr(a, t, t_amnt, 1, 0, n - 1);
    /*for (int j = 0; j<4 * n; j++) {
        cout<<t[j]<<" "<<t_amnt[j]<<endl;
    }*/
    cin >> k;
    for (int j = 0; j < k; j++) {
        cin >> l >> r;
        l--;
        r--;
        cout << max_amnt(t, t_amnt, 1, 0, n - 1, l, r, amount) << " ";
        cout << amount << endl;
    }
}