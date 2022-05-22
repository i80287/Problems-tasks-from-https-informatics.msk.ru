#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	int n,p=3;
	string a;
	cin>>n;
	vector <int> spisok(n);
	for(int i=0;i<n;i++){
		cin>>a;
		int ans=0,g=0;
		for(int j=0;j<7;j++){
			if(a[j]=='a' || a[j]=='b' || a[j]=='c'){
				g=2;
			}else if(a[j]=='d' || a[j]=='e' || a[j]=='f'){
				g=3;
			}else if(a[j]=='g' || a[j]=='h' || a[j]=='i'){
				g=4;
			}else if(a[j]=='j' || a[j]=='k' || a[j]=='l'){
				g=5;
			}else if(a[j]=='m' || a[j]=='n' || a[j]=='o'){
				g=6;
			}else if(a[j]=='p' || a[j]=='q' || a[j]=='r' || a[j]=='s'){
				g=7;
			}else if(a[j]=='t' || a[j]=='u' || a[j]=='v'){
				g=8;
			}else if(a[j]=='w' || a[j]=='x' || a[j]=='y' || a[j]=='z'){
				g=9;
			}
			ans+=g*pow(10,j);
		}
		spisok[i]=ans;
	}
	/*for(int i=0;i<n;i++){
		cout<<spisok[i]<<" ";
	}
	cout<<endl;
	*/
	int povtor=0;
	sort(spisok.begin(),spisok.end());
	for(int i=0;i<n-1;i++){
		if(spisok[i+1]>spisok[i]){
			povtor++;
		}
	}
	cout<<povtor+1;
}