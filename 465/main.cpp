#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,m;
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
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
