#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,m;
	bool yes=1;
	cin>>n>>m;
	vector< vector<int> >a(n,vector<int>(n,0));
	for(int i=0;i<m;++i){
		int bufi,bufj;
		cin>>bufi>>bufj;
		a[bufi-1][bufj-1]=1;
		a[bufj-1][bufi-1]=1;
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(a[i][j]==0 && i!=j) yes=0;
		}
	}
	if(yes) cout<<"YES";
	else cout<<"NO";
}
