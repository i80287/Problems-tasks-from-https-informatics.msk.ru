#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	bool yes=1;
	cin>>n;
	vector< vector<int> >a(n,vector<int>(n));
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;++i){
		if(a[i][i]!=0) yes=0;
	}
	for(int i=1;i<n;++i){
		for(int j=i;j<n;++j){
			if(a[i][j]!=a[j][i]) yes=0;
		}
	}
	if(yes) cout<<"YES";
	else cout<<"NO";
}
