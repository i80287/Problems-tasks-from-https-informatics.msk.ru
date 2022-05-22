#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void t_cr(vector <int> &a, vector <long long int> &t_i, int i, int tl, int tr){
    if(tl==tr){
        t_i[i]=tl;
    }
    else{
        int temp = (tr+tl)/2;
        t_cr(a, t_i, 2*i, tl, temp);
        t_cr(a, t_i, 2*i+1, temp+1, tr);
        if(a[t_i[2*i]]>=a[t_i[2*i+1]]){
            t_i[i]=t_i[2*i];
        }else{
            t_i[i]=t_i[2*i+1];
        }
    }
}
int findmax(vector <int> &a, vector <long long int> &t_i, int i, int tl, int tr, int l, int r){
    //cout<<"     "<<tl<<" "<<tr<<" "<<l<<" "<<r<<endl;
    if(l>r || l>tr){
        return -1;
    }
    if(l==tl && r==tr){
        return t_i[i];
    }
    int temp = (tr+tl)/2;
    if(l>temp){
        return findmax(a, t_i, 2*i+1, temp+1, tr, l, r);
    }else if(r<=temp){
        return findmax(a, t_i, 2*i, tl, temp, l, r);
    }else{
        //cout<<"2343"<<endl;
        int leftc=findmax(a, t_i, 2*i, tl, temp, l, temp);
        int rightc=findmax(a, t_i, 2*i+1, temp+1, tr, temp+1, r);
        if(a[leftc]>=a[rightc]){
            return leftc;
        }
        return rightc;
    }
}
int main()
{
    int n,k, l, r;
    cin>>n;
    vector <int> a(n);
    vector <long long int> t_i(4*n, 0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    t_cr(a, t_i, 1, 0, n-1);
    /*for(int j=0;j<4*n;j++){
        cout<<t[j]<<" "<<t_i[j]<<endl;
    }*/
    cin>>k;
    for(int j=0;j<k;j++){
        cin>>l>>r;
        l--;
        r--;
        cout<<findmax(a, t_i, 1, 0, n-1, l, r)+1<<" ";
    }
}