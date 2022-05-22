#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void t_cr(vector <int> &a, vector <long long int> &t, int i, int tl, int tr){
    if(tl==tr){
        if(!a[tl]){
            t[i]=1;
        }else{
            t[i]=0;
        }
    }else{
        int temp = (tr+tl)/2;
        t_cr(a, t, 2*i, tl, temp);
        t_cr(a, t, 2*i+1, temp+1, tr);
        t[i]=t[2*i] + t[2*i+1];
    }
}
long long int zero(vector <long long int> &t, int i, int tl, int tr, int l, int r){
    //cout<<"     "<<tl<<" "<<tr<<" "<<l<<" "<<r<<" "<<i<<" "<<t[i]<<endl;
    if(l>r){
        return 0;
    }
    if(l==tl && r==tr){
        return t[i];
    }
    int temp = (tr+tl)/2;
    return zero(t, 2*i, tl, temp, l, min(r, temp)) + zero(t, 2*i+1, temp+1, tr, max(l, temp+1), r);

}
int main()
{
    int n,k, l, r;
    cin>>n;
    vector <int> a(n);
    vector <long long int> t(4*n, 0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    t_cr(a, t, 1, 0, n-1);
    /*for(int j=0;j<4*n;j++){
        cout<<t[j]<<" ";//<<t_i[j]<<endl;
    }*/
    cin>>k;
    for(int j=0;j<k;j++){
        cin>>l>>r;
        l--;
        r--;
        cout<<zero(t, 1, 0, n-1, l, r)<<" ";
    }
}