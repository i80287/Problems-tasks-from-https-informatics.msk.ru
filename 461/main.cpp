#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	bool yes=0;
	cin>>n;
	vector< vector<int> >a(n,vector<int>(n));
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;++i){
		if(a[i][i]!=0) yes=1;
	}
	
	if(yes) cout<<"YES";
	else cout<<"NO";
}
